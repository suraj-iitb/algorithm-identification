#include<stdio.h>

int main (){
    int i,j,N,mem;
    int ar[100];
    for(i=0;i<100;i++){
        ar[i]=0;
    }
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&ar[i]);
    }
    for(j=0;j<N;j++){
        printf("%d",ar[j]);
        if(j!=N-1)printf(" ");
    }
    printf("\n");
    
    
    for(i=1;i<N;i++){
        mem=ar[i];
        j=i-1;
        while(j>=0 && ar[j]>mem){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=mem;
        
        for(j=0;j<N;j++){
            printf("%d",ar[j]);
            if(j!=N-1)printf(" ");
        }
        printf("\n");
    }
}
