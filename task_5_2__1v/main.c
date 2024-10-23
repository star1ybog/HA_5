#include <stdio.h>
#include <math.h>
#include "bisection.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double intersection_function(double x) {
    extern double a, b; // Access global variables a and b
    return a * sin(x) - b * cos(x);
}

double a, b;

int main() {
    double left = 0.0, right = M_PI / 2; // Initial search interval
    double tolerance;
    int iterations;

    //input for coefficients and tolerance
    printf("Enter coefficient a: ");
    scanf("%lf", &a);
    printf("Enter coefficient b: ");
    scanf("%lf", &b);
    printf("Enter tolerance for convergence: ");
    scanf("%lf", &tolerance);

    //find the intersection point
    double root = bisection(intersection_function, left, right, tolerance, &iterations);

    //result
    printf("Intersection found at x = %.6lf\n", root);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
