#include <stdio.h>
#include <math.h>

#define e 0.0000001

double fx(double x)
{
	// put first function here
	return x;
}

double gx(double x)
{
	// put second function here
	return 2-x;
}

double diff(double x)
{
	// need this to find the intersestion point of the two functions
	return (fx(x) - gx(x));
}

/* finding the point of intersection using bisection method */
double bisection(double a, double b)
{
	double x;
	
	do{
		if(diff(a) * diff(b) > 0){
			printf("No intersection point between this two\n");
			break;
		}
		
		x=(a+b)/2;
		
		if(diff(a)*diff(x) < 0)
			b=x;
		else
			a=x;

	}while(fabs(diff(x)) > e);
	
	return x;
}

double calculateArea(double (*func)(double x), double start, double end)
{
	double area = 0;
	int n = 100;		// number of divisions
	int i; 				// loop variable	
	
	double h = (end - start)/n;
	double x = start + h; // x = points along x-axis
	for(i=1; i<n; i++)
	{
		area += func(x);
		x = x + h;
	}
	area = area * h;
	area = area + h/2*(func(start) + func(end));
	
	return area;
}

void main()
{	
	double intersection = bisection(0.5, 2.5); // the intersection point is between these two;
	
	double area1 = calculateArea(fx, 0, intersection);
	double area2 = calculateArea(gx, intersection, 2);

	printf("Area: %lf sq units\n", fabs(area1 + area2)); // depending upon the problem it can also be (area1-area2)
}
