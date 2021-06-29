#include <stdio.h>
#define max 1000
void divisor(int,int[max]);

int main(){
    int array[max];
    int leng;
    scanf("%d",&leng);
    for(int i=0;i<leng;i++){
        scanf("%d",&array[i]);
    }

    divisor(leng,array);

    return 0;
}

void divisor(int n,int array[max]){
    int a,j;
    for(int k=0;k<n;k++){
        printf("%d",array[k]);
        if(k<n-1)printf(" ");
    }
    printf("\n");
    for(int i=1;i<n;i++){
        a=array[i];
        j=i-1;
        while(j>=0 && array[j]>a){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=a;

        for(int k=0;k<n;k++){
            printf("%d",array[k]);
            if(k<n-1)printf(" ");
        }
        printf("\n");
    }
}
