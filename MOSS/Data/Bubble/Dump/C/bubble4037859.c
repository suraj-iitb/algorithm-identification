#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int buff[100];
    bool flag=true;
    int counter,tmp,num=0,k;

    scanf("%d",&counter);
    for(int i=0;i<counter;i++){
        scanf("%d",&buff[i]);
    }

    while(flag){
        flag=false;
        for(int j=counter-1;j!=0;j--){
            if(buff[j]<buff[j-1]){
                tmp=buff[j];
                buff[j]=buff[j-1];
                buff[j-1]=tmp;
                flag=true;
                num++;
            }
        }
    }

    for(k=0;k<counter-1;k++){
        printf("%d ",buff[k]);
    }

    printf("%d\n",buff[k]);
    printf("%d\n",num);

    return 0;


}


