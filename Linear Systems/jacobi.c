#include <stdio.h>
#include <math.h>
#include <string.h>

#define e 0.000001

double f1(		 double x2, double x3)
{
	// put 1st equation here
	return ((85 - 3*x2 + 2*x3)/15);
}

double f2(double x1,		double x3)
{
	// put 2nd equation here
	return ((51 - 2*x1 - x3)/10);
}

double f3(double x1, double x2		 )
{
	// put 3rd equation here
	return ((5-x1 + 2*x2)/8);
}

/* sample input is
	15x + 3y  - 2z = 85
	2x  + 10y + z  = 51
	x   - 2y  + 8z = 5
	
	(and remember the coefficients along the diagonal must be greater than the sum of the other two)
*/

void main()
{
	int found = 0, counter = 0;
	int i;	// loop variable
	
	double xn[3], xo[3];	// xn = new value, xo = old value
	
	for(i=0; i<3; i++)
	{
		xn[i] = xo[i] = 0;	// initializing both to zero
	}
	
	while(!found)
	{
		xn[0] = f1(		 xo[1], xo[2]);
		xn[1] = f2(xo[0],		xo[2]);
		xn[2] = f3(xo[0], xo[1]		 );
		
		found = 1;
		
		for(i=0; i<3; i++){
			if(fabs(xn[i] - xo[i]) > e)
				found = 0;
			xo[i] = xn[i];
		}
		counter++;
	}
	
	printf("Ans: ");
	for(i=0; i<3; i++)
	{
		printf("%lf ", xn[i]);
	}
	printf("\nIterations: %d\n", counter);
}
