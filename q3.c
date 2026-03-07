/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Write C programs to evaluate the following functions to $0.0001% accuracy.
(a) sin x = x - x^3/3! + x^5/5! - x^7/7! + ... 
(b) cos x = 1 - x^2/2! + x^4/4! - x^6/6! + ...
(c) SUM = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
*/


// (a) sin x = x - x^3/3! + x^5/5! - x^7/7! + ...
#include<stdio.h>
#include<math.h>
double find_sin(double x){
    double term = x;
    double sum = x;
    int i;
    for(i=1;fabs(term/sum)>0.000001;i++){
        term = -term*x*x/((2*i)*(2*i+1));
        sum += term;
    }
    return sum;
}
int main(){
    double x;
    printf("Enter a value: ");
    scanf("%lf",&x);
    printf("sin(%.2f rad) = %.8f\n",x,find_sin(x));
    return 0;
}


/*
// (b) cos x = 1 - x^2/2! + x^4/4! - x^6/6! + ...
#include<stdio.h>
#include<math.h>
double find_cos(double x){
    double term = 1.0;
    double sum = 1.0;
    int i;
    for(i=1;fabs(term/sum)>0.000001;i++){
        term = -term*x*x/((2*i)*(2*i-1));
        sum += term;
    }
    return sum;
}
int main(){
    double x;
    printf("Enter a value: ");
    scanf("%lf",&x);
    printf("cos(%.2f rad) = %.8f\n",x,find_cos(x));
    return 0;
}
*/

/*
// (c) SUM = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
#include<stdio.h>
#include<math.h>
double find_sum(double x){
    double term = 1.0;
    double sum = 0;
    int i = 1;
    do{
        term = pow((1.0/i),i);
        sum += term;
        i++;
    }while(term/sum>0.000001);
    return sum;
}
int main(){
    double x;
    printf("Enter a value: ");
    scanf("%lf",&x);
    printf("Sum = %.8f\n",find_sum(x));
    return 0;
}
*/
