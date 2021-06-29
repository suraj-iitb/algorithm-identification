#include <stdio.h>
int main(){
    int i,j;
    int A[100],N,num=0,min,v;
    
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

    for(i=0;i<N;i++){
        min = i;
        for(j=i;j<N;j++){
            if(A[min] > A[j]){min = j;
                
            }
        }
        v = A[min];
        A[min] = A[i];
        A[i] = v;
        if(i != min) num++;
    }
    
    printf("%d",A[0]);
    for(i=1;i<N;i++) printf(" %d",A[i]);
    printf("\n");
    printf("%d\n",num);
    
    return 0;  
}
