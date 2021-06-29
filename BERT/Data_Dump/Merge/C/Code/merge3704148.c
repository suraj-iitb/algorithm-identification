#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *A,int length);
void Merge(int *A, int *Left, int *Right, int length);

int track = 0;
/*
 * 
 */
int main(int argc, char** argv) {

    int n;
    scanf("%d",&n);
    int *A = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    MergeSort(A,n);
    
    for(int i= 0; i < n; i++){
        printf("%d",A[i]);
        if(i < n - 1)printf(" ");
    }
    printf("\n%d",track);
    printf("\n");
    return (0);
}

void MergeSort(int *A, int length){
    
    int *Left, *Right;
    int mid = length/2;
    int i = 0;
    if(length < 2)return;
    else{
        Left = (int*)malloc(mid*sizeof(int));
        Right = (int*)malloc((length - mid)*sizeof(int));
        
    for(int i = 0; i < mid; i++){
        Left[i] = A[i];
    }
    for(int i = mid; i < length; i++){
        Right[i - mid] = A[i];
    }
    }
    MergeSort(Left,mid);
    MergeSort(Right,length-mid);
    Merge(A,Left,Right,length);
}

void Merge(int *A, int *Left, int *Right, int length){
    int i= 0, j=0, k=0;
    int Leftmid, Rightmid;
    Leftmid = length/2;
    Rightmid = length - Leftmid;
    
    while(i < Leftmid && j < Rightmid){
        if(Left[i] < Right[j]){
            A[k] = Left[i];
            i++;
            track++;
        }
        else{
                A[k] = Right[j];
                j++;
                track++;
        }
        k++;
        
    }
        
        while(i < Leftmid){
            A[k]=Left[i];
            i++;
            k++;
            track++;
        }
        while(j<Rightmid){
            A[k]=Right[j];
            j++;
            k++;
            track++;
        }
    }

