/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Write a C program that will read and store the details of a list of students in the format:
Roll No.       Name       Marks obtained
-------      --------        --------
-------      --------        --------
-------      --------        --------
and produce the following output lists:
(a) Alphabetical list of names, roll numbers and marks obtained.
(b) List sorted on roll numbers.
(c) List sorted on marks (rank-wise list)
*/

#include<stdio.h>
#include<string.h>
struct Student{
    int roll_no;
    char name[50];
    float marks;
};
int main(){
    int n, i, j;
    struct Student s[100], temp;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);
        printf("Name: ");
        scanf(" %99[^\n]s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(strcmp(s[j].name, s[j + 1].name) > 0){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\n--- Alphabetical List ---\n");
    for(i = 0; i < n; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(s[j].roll_no > s[j + 1].roll_no){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\n--- Sorted by Roll No ---\n");
    for(i = 0; i < n; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    } 
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(s[j].marks < s[j + 1].marks){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\n--- Rank-wise List (Marks) ---\n");
    for(i = 0; i < n; i++){
        printf("%d\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    } 
    return 0;
}