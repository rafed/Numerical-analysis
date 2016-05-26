#include <stdio.h>
#include <math.h>

#define e 0.000001

double f(double x){
	// put function here	
	return x*x - 29;
}

double fp(double x){
	// put derivative of function here	
	return 2*x;
}

double newtonRaphson(double a, double b)
{
	int counter = 0;
	double root;
	
	do{
		if(f(a) * f(b) > 0){
			printf("Root not found in this range.\n");
			break;
		}
		
		root = b-(f(b)/fp(b));
		
		b = root;
		
		counter++;
	}while(fabs(f(root)) > e);
	
	printf("Newton-Raphson's method, %d iterations\n", counter);
	
	return root;
}

void main()
{
	double root = newtonRaphson(2, 6); 	// finding between this range
	printf("The root is %lf.\n", root);	
}
