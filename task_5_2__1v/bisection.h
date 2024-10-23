#ifndef BISECTION_H
#define BISECTION_H

typedef double (*FunctionPointer)(double); // Function pointer type

// Function declaration for bisection search
double bisection(FunctionPointer func, double a, double b, double tolerance, int *iterations);

#endif // BISECTION_H
