#include <stdio.h>
#include <math.h>

double equation(double x){
	// put equation here
	return x;		// y = x
}

double calculateArea(double(*fx)(double x), int n /*num of divisions*/, double start, double end)
{
	double so, se; 				// so = sum of odd, se = sum of even
	so = se = 0;
	double h = (end - start)/n;	// number of divisions along x-axis
	double x = start + h;		// x = current point
	int i;						// loop variable
	
	for(i=1; i<n; i++)
	{
		if(i % 2 == 0)
			se += fx(x);
		else
			so += fx(x);
			
		x = x + h;
	}
	
	return h/3 * (fx(start) + fx (end) + 4*so + 2*se);	// simpsons 1/3 rule
}

main()
{
   double area = calculateArea(equation, 100, 0, 2);
   printf("Area: %lf sq units\n", area);
}
