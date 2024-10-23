#include <stdio.h>
#include <math.h>

//compute the square root using the Babylonian method
double babylonian_sqrt(double num, double tolerance, int *iterations) {
    double guess = num / 2.0;  // Initial guess
    double next_guess;
    *iterations = 0;  // Initialize the iteration counter

    do {
        next_guess = (guess + num / guess) / 2.0;  // Babylonian formula
        (*iterations)++;  //iteration counter
    } while (fabs(next_guess - guess) > tolerance);  // Check for convergence

    return next_guess;
}

int main() {
    double num, tolerance;
    int iterations;

    printf("Enter the number to find the square root of: ");
    scanf("%lf", &num);
    
    if (num <= 0) {
        printf("Error: Please enter a positive number.\n");
        return 1;
    }

    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    // Call function
    double result = babylonian_sqrt(num, tolerance, &iterations);

    // Print the result and the number of iterations
    printf("Number of iterations: %d\n", iterations);
    printf("Approximate square root: %.6f\n", result);

    return 0;
}
