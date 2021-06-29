#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int N = 0;
    scanf("%d",&N);    
    int arr[N];
    int counter, j, temp, aaa;
    int ppp = 0;
    for(counter=0;counter<N;counter++){
        scanf("%d",&arr[counter]);
    }
    for(counter=0;counter<N;counter++){
        temp = counter;
        for(j=counter;j<N;j++){
            if (arr[j]<arr[temp]){
               temp = j; 
            }
        }
        if(temp != counter){
            aaa = arr[counter];
            arr[counter] = arr[temp];
            arr[temp] = aaa;
            ppp++;
        }
    }
    for(j=0; j<N; j++){
        printf("%d",arr[j]);
        if(j != N-1) printf(" ");
    }
    printf("\n%d\n",ppp);
    return 0;
}
