#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int N = 0;
    scanf("%d",&N);    
    int arr[N];
    int counter, j, temp;
    int ppp = 0;
    for(counter=0;counter<N;counter++){
        scanf("%d",&arr[counter]);
    }
    for(counter=0;counter<N;counter++){
        for(j=N-1; j>counter; j--){
            if (arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp; 
                ppp = ppp+1;
            }
        } 
    }
    for(j=0; j<N; j++){
        printf("%d",arr[j]);
        if(j != N-1) printf(" ");
    }
    printf("\n%d\n",ppp);
    return 0;
}
