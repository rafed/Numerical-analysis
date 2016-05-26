#include <stdio.h>
#include <math.h>

#define e 0.000001

double f(double x){
	// put function here	
	return x*x - 29;
}

double falsePosition(double a, double b)
{
	int counter = 0;
	double root;
	
	do{
		if(f(a) * f(b) > 0){
			printf("Root not found in this range.\n");
			break;
		}
		
		root = (a*f(b) - b*f(a))/(f(b) - f(a));
		
		if(f(a) * f(root) < 0)
			b = root;
		else
			a = root;
		
		counter++;
	}while(fabs(f(root)) > e);
	
	printf("False position method, %d iterations\n", counter);
	
	return root;
}

void main()
{
	double root = falsePosition(2, 6); 	// finding between this range
	printf("The root is %lf.\n", root);	
}
