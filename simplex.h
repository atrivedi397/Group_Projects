void print()
{
    std::cout<<"\nThis is a program for solving Linear programming Problems. \n"<<std::endl;
}


struct coefficients
{
    bool if_present;
    float value;
};


///variables are used as x1 , x2, x3 ......xn
class operations
{
    ///m is the no. of rows equals no. of constraints , n is no. of columns(including slack)
    int no_of_equ, no_variables , m ,  n ;
    coefficients** matrix; float* B;
public:

    ///default constructor
    operations()
    {
        int a,b;
        std::cout<<"\nInput the number of variables.\n";
        std::cin>>a;
        std::cout<<"\nInput the number of constraints.\n";
        std::cin>>b;
        no_of_equ = b;
        no_variables = a;

        ///hence n will be total variables + slack(no. of equ)
        m = no_of_equ; n = no_variables + no_of_equ;

        ///RHS value matrix declared
        B = new float[m];

        ///2D Matrix created
        ///getting pointer to array[1][n](a row of n columns)
        matrix = new coefficients*[no_variables];
        for(int i = 0; i < no_variables; i++)
            matrix[i] = new coefficients[no_of_equ];   ///expanding the array into multiple rows
    }

    ///Destructor to delete the 2D matrix and the RHS value matrix
    ~operations()
    {
        for(int i = 0; i < no_of_equ; i++)
            delete[] matrix[i];
        delete[] matrix;
        delete[] B;
    };

    void total_input();
    void display_constraints();
};

void operations::total_input()
{
    int test_value;

    for(int i = 0; i < no_of_equ; i++)
    {
        std::cout<<"\nTaking inputs for the "<<i+1<<" constraint\n";
        for (int j = 0; j < no_variables; j++)
        {
            std::cout<<"\nInput the coefficient for variable x"<<j+1<<" to store :  ";
            std::cin>>test_value;
            {
                matrix[i][j].value = test_value;
                if(test_value == 0)
                    matrix[i][j].if_present = 0;
                else
                    matrix[i][j].if_present = 1;
            }
        }

        ///taking inputs for the RHS column vector

        std::cout<<"\nEnter the value of corresponding RHS 'B' matrix : ";
        std::cin>>B[i];
    }
}

void operations::display_constraints()
{
    std::cout<<"\nThe Constraints equations are :\n";

    for (int i = 0; i < no_of_equ; ++i)
    {
        std::cout<<"\nThe constraint "<<i+1<<" is : \n";
        for (int j = 0; j < no_variables; ++j)
        {
            ///only displaying the variables with non-zero coefficients value
            if(matrix[i][j].if_present != 0)
                std::cout<<matrix[i][j].value<<"x"<<j+1<<" + ";
        }
        std::cout<<" <= "<<B[i]<<std::endl;
    }
}




// Created by atrivedi on 5/27/18.


