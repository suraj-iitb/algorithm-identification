#include<stdio.h>
#define N 100

int main(){
    int array[N];
    int n,i,j,v,k;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    
    for(k=0;k<n-1;k++){
        printf("%d ",array[k]);
    }
    printf("%d\n",array[k]);
    
    for(i=1;i<n;i++){
        v = array[i];
        j = i-1;
        while(j>=0 && array[j]>v){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = v;
        
        for(k=0;k<n-1;k++){
            printf("%d ",array[k]);
        }
        printf("%d\n",array[k]);
    }
    
    return 0;
}

