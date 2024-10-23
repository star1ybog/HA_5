#include <stdio.h>
#include <math.h>
#include "bisection.h"

// Bisection method implementation
double bisection(FunctionPointer func, double left, double right, double tolerance, int *iterations) {
    double mid;

    *iterations = 0; // Initialize iteration count

    while ((right - left) / 2.0 > tolerance) {
        mid = (left + right) / 2.0;
        (*iterations)++;

        // If the function value at mid is close enough to zero, return mid as root
        if (fabs(func(mid)) < tolerance) {
            return mid;
        }

        // Decide the side to proceed based on sign change
        if (func(left) * func(mid) < 0) {
            right = mid;
        } else {
            left = mid;
        }
    }

    // Return approximate root
    return (left + right) / 2.0;
}
