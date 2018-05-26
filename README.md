Simplex method
==============


Simplest case (ie variables are non-zero positive, restricted value with less than or equal conditions)

Requirements (as in inputs)
1) Objective function coefficients
2) Inequalities (pressumed as yet)
3) Constraints Coefficients
4) Details about variables as being un/restricted (latter case here)


Requirements (as in implementations)
1) An array<float> : for storing objective function
2) An array<struct> : for marking variables as basic or non basic
	(struct = basic<bool> + value<float>)
3) A 2D [m*n] matrix to store the coefficients of the constraints 
4) An array<float> : for calculating "Zj" (for checking function values at different points)
5) An array<float> : for calculating "Cj-Zj" (for finding the incoming variable)
6) An array<float> : for storing ratio (as to find the "to-be-replaced" variable)
7) 1 variable : to store 'key column' index number
8) 1 variable : to store 'key row' index number
9) 1 variable : to store 'key element' or an array[1x2] : to store key element index number
10) An array<float> : to store 'B' (RHS of constraints) 
** The above pre-requisite may not be neccesarily needed. And some important requirement may remain unknown untill some time.
