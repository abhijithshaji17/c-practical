/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Distance between 2 points (x1,y1) and (x2,y2) is given by D = sqrt((x2-x1)^2 + (y2-y1)^2). Write a program to calculate radius, area, and perimeter of the circle using separate functions. Use proper header files, include the concept of typecasting, symbolic constants.
*/

#include<stdio.h>
#include<math.h>
#define pi 3.14
float radius();
float area(float r);
float perimeter(float r);
int main(){
    float r = radius();
    printf("Radius = %.2f\n",r);
    printf("Area of circle = %.2f\n",area(r));
    printf("Perimeter of circle = %.2f\n",perimeter(r));
}
float radius(){
    float x1,y1,x2,y2;
    printf("Enter values for x1,y1,x2,y2: ");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    double D = sqrt(pow((double)(x2-x1),2)+pow((double)(y2-y1),2));
    return (float)(D/2.0);
}
float area(float r){
    return (float)(pi*pow(r,2));
}
float perimeter(float r){
    return (float)(2*pi*r);
}