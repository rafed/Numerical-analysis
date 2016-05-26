#include <stdio.h>
#include <math.h>

#define e 0.000000001

double fx(double x){
	// put your function here (here it is y=x^2)
	return x*x;
}

void main()
{	
	double a = 0.0;			// starting point
	double b = 2.0;			// ending point
	
	int n = 200;			// number of segments to divide
	double h = (b-a)/n;		// length of each segment
	
	double df; 				// value of differentiation
	int i;					// loop variable
	
	/* for first point we use forward differentiation */
	df = (fx(a+h) - fx(a))/h;
	printf("%lf, %lf %lf\n", a, fx(a), df);
	
	/* for the middle points we use centratl differentiation */
	double x = a;			// x = current point
	for(i=1; i<n; i++){
		x = x+h;			// increasing h distance each time
		df = (fx(x+h)-fx(x-h))/(2*h);
		printf("%lf, %lf, %lf\n", x, fx(x), df);
	}
	
	/* for last point we use backward differentiation */
	df = (fx(b) - fx(b-h))/h;
	printf("%lf, %lf, %lf\n", b, fx(b), df);
}
