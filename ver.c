#include <stdio.h>
#include <math.h>

int main() {
    // Declarations for variables used throughout the program
    double term, x;
    int n;

    // --- SIN(X) ---
    double sinx = 0;
    printf("Enter the value of x (in radians) for sin/cos: ");
    scanf("%lf", &x); // Now you can actually test values like 3.14159/2 (90 degrees)
    
    term = x;
    n = 1;
    sinx = x;

    printf("\nCalculating sin(%lf)...\n", x);
    while(1){
        term *= (-x * x) / ((n + 1) * (n + 2));
        sinx += term;

        n += 2;
        if(fabs(term) < 0.0000001) break;
    }
    printf("\nsin(%lf) : %lf\n", x, sinx);

    // --- COS(X) ---
    double cosx = 0;
    // x remains the same as entered above
    term = 1;
    n = 1; // Used as the starting point for (n)*(n+1) which becomes (1)*(2)
    cosx = 1;

    printf("\nCalculating cos(%lf)...\n", x);
    while(1){
        term *= (-x * x) / ((n) * (n + 1));
        cosx += term;

        n += 2;
        if(fabs(term) < 0.0000001) break;
    }
    printf("\ncos(%lf) : %lf\n", x, cosx);

    // --- SUM OF (1/n)^n ---
    double sum = 0;
    term = 1;
    n = 1;
    sum = 0; // Reset sum for the loop

    printf("\nCalculating sum of (1/n)^n...\n");
    while(1){
        term = pow(1.0 / n, n);
        sum += term;
        printf("%lf + ", term);
        n += 1;
        if(term < 0.0000001) break;
    }
    printf("\nsum : %lf\n", sum);

    return 0;
}