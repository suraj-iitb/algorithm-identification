#include  <stdio.h>
#define N 100
int main(){
    int i,j,k;
    int A[1000],v,num;
    
    scanf("%d",&num);
    for(i=0;i<num;i++) scanf("%d",&A[i]);
    
    for(i=0;i<num;i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
	printf("%d",A[0]);
         for(k=1;k<num;k++) printf(" %d",A[k]);
         printf("\n");
    }
    return 0;
}
