#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int discover;
    int finish;
}Depth;

void printMatrix(int s,int[s][s]);
void fillMatrix(int s,int[s][s]);
void getDepth(int s,int[s][s],Depth[]);
int findDepth(int,int,int s,int[s][s],Depth[]);
void initDepth(Depth*);
void printDepth(int,Depth);

int main(int argc, char** argv) {
    int size;
    scanf("%d", &size);
    int matrix[size][size];
    Depth depthMat[size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            matrix[i][j] = 0;
        initDepth(&depthMat[i]);
    }
    fillMatrix(size,matrix);
    getDepth(size,matrix,depthMat);
    for(int i = 0; i < size; i++)
        printDepth(i,depthMat[i]);
//    printMatrix(size,matrix);
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

void getDepth(int size, int mat[size][size], Depth dep[size]){
    int time = 1;
    for(int i = 0; i < size; i++){
        if(dep[i].discover == 0)
            time = findDepth(time,i,size,mat,dep) + 1;
    }
}

int findDepth(int time, int current, int size, int mat[size][size], Depth dep[size]){
    if(dep[current].discover == 0)
        dep[current].discover = time++;
    for(int i = 0; i < size; i++){
        if(mat[current][i] == 1 && dep[i].discover == 0)
            time = findDepth(time,i,size,mat,dep) + 1;
    }
    if(dep[current].finish == 0)
        dep[current].finish = time;
    return time;
}

void initDepth(Depth *d){
    d->discover = 0;
    d->finish = 0;
}

void printDepth(int i, Depth d){
    printf("%d %d %d\n", i+1, d.discover, d.finish);
}

