#include <stdio.h>
#include <assert.h>
#include "bisection.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define a simple test function: f(x) = sin(x) - cos(x)
double test_function(double x) {
    return sin(x) - cos(x);
}

void run_tests() {
    int iterations;

    // Test the bisection method with known inputs
    double root = bisection(test_function, 0.0, M_PI / 2, 0.0001, &iterations);
    
    // Check if the result is close to the expected value (pi/4)
    assert(fabs(root - M_PI / 4) < 0.0001);
    
    printf("Test passed: Intersection found at x = %.6lf\n", root);
}

int main() {
    run_tests();
    return 0;
}
