#include <stdio.h>
#include <stdlib.h>




typedef struct{
    int value;
    int done;
}data;


    

int BinarySearch(int n, int key, data *A){
    int Left = 0;
    int Right = n;
    int mid;
    while(Left < Right){
        mid = (Left + Right)/2;
        if(A[mid].value == key)return mid;
        if(key < A[mid].value){
            Right = mid;
        }
        else if(key > A[mid].value){
            Left = mid + 1;
        }
    }
    return -1;
    
}

int main() {

    int n;
    int m;
    scanf("%d",&n);
    data *input = (data*)malloc(n * sizeof(data));
    for (int i = 0; i < n; i++){
        scanf("%d",&input[i].value);
        
    }
    
    scanf("%d",&m);
    int key, track = 0, Pos = 0;
    for(int i = 0; i < m; i++){
        scanf("%d",&key);
         Pos = BinarySearch(n,key,input);
       if(Pos == -1)continue;
        if(input[Pos].done != 1){
        input[Pos].done = 1;
        track++;
        }
    }

    printf("%d",track);
    printf("\n");
    return 0;
}

