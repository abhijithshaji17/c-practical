/*
Name = Abhijith Shaji
Roll No. = 25020144
Department = Department of Computer Science(DCS)
*/

/*
Write a C program using functions to read an m x n matrix and find all saddle points and to find second largest element without sorting. Hint: A saddle point is an element which is smallest in its row but largest in its column. If no saddle point exists, display an appropriate message. 
i/p (Input):
3 1 3
3 2 4
0 6 5
o/p (Output):
Saddle Point = 3 at position 1st row 1st column.
*/

#include<stdio.h>
#include<limits.h>
// Function to find the second largest element without sorting
void find_SecondLargest(int a[100][100],int m,int n){
    int i,j,first = INT_MIN, second = INT_MIN;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]>first){
                second = first;
                first = a[i][j];
            }else if(a[i][j]>second&&a[i][j]!=first){
                second = a[i][j];
            }
        }
    }
    if(second==INT_MIN){
        printf("\nNo second largest element found.");
    }else{
        printf("\nSecond largest element: %d",second);
    }
}
// Function to find and display all saddle points
void find_SaddlePoints(int a[100][100], int m, int n) {
    int found = 0; // Declare 'found' here

    // We need to loop through every row 'i'
    for (int i = 0; i < m; i++) {
        
        // Step 1: Find the minimum element in the current row (i)
        int min_row = a[i][0];
        int col_index = 0;
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min_row) {
                min_row = a[i][j];
                col_index = j;
            }
        }

        // Step 2: Check if this min_row is the LARGEST in its column (col_index)
        int is_saddle = 1; 
        for (int k = 0; k < m; k++) {
            if (a[k][col_index] > min_row) {
                is_saddle = 0; // Found a larger number in the column
                break;
            }
        }

        // Step 3: If it passed the column test, it's a saddle point
        if (is_saddle == 1) {
            printf("\nSaddle point = %d at position Row %d, Column %d", min_row, i + 1, col_index + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo Saddle point exists in the matrix.");
    }
}
int main(){
    int m,n,i,j,a[100][100];
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter the matrix elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Element[%d%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    find_SaddlePoints(a, m, n);
    find_SecondLargest(a, m, n);
    printf("\n");
    return 0;
}