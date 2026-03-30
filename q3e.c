/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Write a C program to evaluate the following functions to $0.0001% accuracy.
(a) sin x = x - x^3/3! + x^5/5! - x^7/7! + ... 
(b) cos x = 1 - x^2/2! + x^4/4! - x^6/6! + ...
(c) SUM = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
*/

#include <stdio.h>
#include <math.h>
int main() {
    double term, x;
    int n;
    double sinx = 0;
    printf("Enter the value of x (in radians) for sin/cos: ");
    scanf("%lf", &x);
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
    double cosx = 0;
    term = 1;
    n = 1;
    cosx = 1;
    printf("\nCalculating cos(%lf)...\n", x);
    while(1){
        term *= (-x * x) / ((n) * (n + 1));
        cosx += term;
        n += 2;
        if(fabs(term) < 0.0000001) break;
    }
    printf("\ncos(%lf) : %lf\n", x, cosx);
    double sum = 0;
    term = 1;
    n = 1;
    sum = 0;
    printf("\nCalculating sum of (1/n)^n...\n");
    while(1){
        term = pow(1.0 / n, n);
        sum += term;
        n += 1;
        if(term < 0.0000001) break;
    }
    printf("\nsum : %lf\n", sum);
    return 0;
}