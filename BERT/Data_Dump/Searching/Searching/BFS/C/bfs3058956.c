#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printMatrix(int s,int[s][s]);
void fillMatrix(int s,int[s][s]);
void getBreadth(int s, int[s][s], int[]);
void findBreadth(int s, int[s][s], int[], int, int);
int min(int,int);

int main(int argc, char** argv) {
    int size;
    scanf("%d", &size);
    int matrix[size][size];
    int breadth[size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            matrix[i][j] = 0;
        breadth[i] = INT_MAX;
    }
    fillMatrix(size,matrix);
    getBreadth(size, matrix, breadth);
    for(int i = 0; i < size; i++){
        if(breadth[i] == INT_MAX)
            breadth[i] = -1;
        printf("%d %d\n",i+1,breadth[i]);
    }
    return (EXIT_SUCCESS);
}

void printMatrix(int size, int mat[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d", mat[i][j]);
            if(j != size-1)
                printf(" ");
        }
        printf("\n");
    }
}

void fillMatrix(int size, int mat[size][size]){
    int loc, count, adjacent;
    for(int i = 0; i < size; i++){
        scanf("%d %d",&loc, &count);
        if(count > 0)
            for(int j = 0; j < count; j++){
                scanf("%d", &adjacent);
                mat[loc-1][--adjacent] = 1;
            }
    }
}

void getBreadth(int size, int mat[size][size], int bread[size]){
    int brdth = 0;
    bread[0] = 0;
    findBreadth(size,mat,bread,0,brdth);
}

void findBreadth(int size, int mat[size][size], int bread[size], int current, int brdth){
    bread[current] = min(bread[current],brdth);
    for(int i = 0; i < size; i++)
        if(mat[current][i] && current != i && bread[i] > brdth)
            findBreadth(size,mat,bread,i,brdth+1);
}

int min (int a, int b){
    if(a < b) return a;
    return b;
}

