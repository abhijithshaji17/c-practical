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
int minrow_check(int rows, int columns, int matrix[rows][columns], int row_idx);
int maxcol_check(int rows, int columns, int matrix[rows][columns], int col_idx);
int second_largest(int rows, int columns, int matrix[rows][columns]);
void saddle(int rows, int columns, int matrix[rows][columns]);
int main(){
    int m, n, i, j;
    printf("Enter number of rows and columns: ");
    if(scanf("%d %d", &m, &n) != 2) return 1;
    int a[m][n]; 
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("Element[%d%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    saddle(m, n, a);
    int sl = second_largest(m, n, a);
    int sl_row = sl / n;
    int sl_col = sl % n;
    printf("Second largest element at %d,%d = %d\n", sl_row + 1, sl_col + 1, a[sl_row][sl_col]);
    return 0;
}
int second_largest(int rows, int columns, int matrix[rows][columns]){
    int first = matrix[0][0]; 
    int second = -2147483647;
    int first_idx = 0, second_idx = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if (matrix[i][j] > first){
                second = first;
                second_idx = first_idx;
                first = matrix[i][j];
                first_idx = (i * columns) + j;
            }else if(matrix[i][j] > second && matrix[i][j] < first){
                second = matrix[i][j];
                second_idx = (i * columns) + j;
            }
        }
    }
    return second_idx;
}
void saddle(int rows, int columns, int matrix[rows][columns]){
    int found = 0;
    for (int i = 0; i < rows; i++){
        int min_col = minrow_check(rows, columns, matrix, i);
        int max_row = maxcol_check(rows, columns, matrix, min_col);
        if (max_row == i){
            found++;
            printf("Saddle point at %d,%d = %d\n", i + 1, min_col + 1, matrix[i][min_col]);
        }
    }
    if(found) printf("Found %d saddle points!\n", found);
    else printf("Found no saddle points!\n");
}
int minrow_check(int rows, int columns, int matrix[rows][columns], int row_idx){
    int min_val = matrix[row_idx][0];
    int min_col = 0;
    for(int j = 1; j < columns; j++){
        if(matrix[row_idx][j] < min_val){
            min_val = matrix[row_idx][j];
            min_col = j;
        }
    }
    return min_col;
}
int maxcol_check(int rows, int columns, int matrix[rows][columns], int col_idx){
    int max_val = matrix[0][col_idx];
    int max_row = 0;
    for(int i = 1; i < rows; i++){
        if(matrix[i][col_idx] > max_val){
            max_val = matrix[i][col_idx];
            max_row = i;
        }
    }
    return max_row;
}