#include <stdio.h>
#define N 100
int main(){
    int i,j;
    int buffer[N];
    int input,key;

    /*make buffer*/
    scanf("%d",&input);

    /*input element of buffer*/
    for(i=0;i<input;i++){
        scanf("%d",&buffer[i]);
    }

    for(j=0;j<input;j++){
            if(j==input-1)printf("%d",buffer[j]);
            else printf("%d ",buffer[j]);
        }
        printf("\n");

    for(i=1;i<input;i++){
        key = buffer[i];
        j = i - 1;
        while(j>=0 && buffer[j] > key){
            buffer[j+1] = buffer[j];
            j--;
        }
        buffer[j+1] = key;
        for(j=0;j<input;j++){
            if(j==input-1)printf("%d",buffer[j]);
            else printf("%d ",buffer[j]);
        }
        printf("\n");
    }

    return 0;
}
