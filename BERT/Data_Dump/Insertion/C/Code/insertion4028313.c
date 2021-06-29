#include <stdio.h>
#include <stdlib.h>


int main(){
    int num,tmp;
    int buff[100];

    scanf("%d",&num);

    for(int i=0;i<num;i++){
        scanf("%d",&buff[i]);
    }

    for(int j,i=0;i<num;i++){
        tmp=buff[i];
        j=i-1;
        while(j>=0&&buff[j]>tmp){
            buff[j+1]=buff[j];
            j--;
        }
        buff[j+1]=tmp;
        for(int k=0;k<num;k++){
            if(k==num-1){
                printf("%d",buff[k]);
                continue;
            }
            printf("%d ",buff[k]);
        }
            printf("\n");
    }
    return 0;
}

