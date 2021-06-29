#include <stdio.h>
int main(void){
    int Length,Temp,i,j;
    scanf("%d",&Length);
    int Data[Length];
    for(i=0;i<Length;i++){
        scanf("%d ",&Data[i]);
        printf("%d",Data[i]);
        if(i!=Length-1)
            printf(" ");
    }
    printf("\n");
    for(i=1;i<Length;i++){
        Temp=Data[i];
        j=i-1;
        while(j>=0 && Data[j]>Temp){
            Data[j+1]=Data[j];
            j--;
        }
        Data[j+1]=Temp;
        for(j=0;j<Length;j++){
            printf("%d",Data[j]);
            if(j!=Length-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

