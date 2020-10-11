#include <stdio.h>
#include <stdlib.h>


int main(){
    int buff[100];
    int counter,num=0,min,l,tmp;

    scanf("%d",&counter);
    for(int i=0;i<counter;i++){
        scanf("%d",&buff[i]);
    }

    for(int j=0;j<counter;j++){
        min=j;
        for(int k=j;k<counter;k++){
            if(buff[k]<buff[min]){
                min=k;
            }
        }
        tmp=buff[j];
        buff[j]=buff[min];
        buff[min]=tmp;
        if(j!=min)
            num++;
    }

    for(l=0;l<counter-1;l++){
        printf("%d ",buff[l]);
    }
    printf("%d\n",buff[l]);

    printf("%d\n",num);

    return 0;

}

