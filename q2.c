/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Write program to read marks of three subjects out of 100 from user. Use seperate functions to
(a) Find the largest among the numbers using nested if.
(b) Find smallest among the numbers using if else if statements.
(c) Calculate the average of the largest and smallest number and if the average is greater than third number assign the value one to a new variable V Otherwise assign a value 0 to the new variable V (use conditional operators here).
*/

#include<stdio.h>
float largest(float,float,float);
float smallest(float,float,float);
void average(float,float,float);
int main(){
    float m1,m2,m3,third;
    printf("Enter the marks out of 100 of 3 subjects: ");
    scanf("%f %f %f",&m1,&m2,&m3);
    float l = largest(m1,m2,m3);
    printf("%.2f is the highest mark.\n",l);
    float s = smallest(m1,m2,m3);
    printf("%.2f is the lowest mark.\n",s);
    third = (m1+m2+m3) - (l+s);
    average(l,s,third);
    return 0;
}
float largest(float x,float y,float z){
    if(x>=y){
        if(x>=z){
            return x;
        }else{
            return z;
        }
    }else{
        if(y>=z){
            return y;
        }else{
            return z;
        }
    }
}
float smallest(float a,float b,float c){
    if(a<=b && a<=c){
        return a;
    }else if(b<=a && b<=c){
        return b;
    }else{
        return c;
    }   
}
void average(float p,float q,float r){
    int V;
    float avg = (p+q)/2;
    printf("Average mark = %.2f",avg);
    V = (avg>r)?1:0;
    printf("\nV = %d\n",V);
}
