#include <stdio.h>
#define MAX 2000000

int main(){
    int i,j,n,max,data;
    
    scanf("%d",&n);
    int B[MAX];
    
    for(i=0;i<MAX;i++){
        B[i]=0;
    }

    max=0;

    for(i=0;i<n;i++){
        scanf("%d",&data);
        B[data]++;
        if(max<data)max=data;
        
    }
    
    
    j=0;
    for(i=0;i<max||j<n;i++){
        while(B[i]>0){
            printf("%d",i);
            j++;
            B[i]--;
            if(j!=n)printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
