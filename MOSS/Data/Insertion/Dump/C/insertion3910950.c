#include<stdio.h>

int main(void){

int i, j, k, n, v;
int A[100];

scanf("%d",&n);

for(i=0;i<n;i++){
    scanf("%d",&A[i]);
}

for(k=0;k<n-1;k++){
    printf("%d ",A[k]);
}
printf("%d\n",A[n-1]);

for(i=1;i<n;i++){
    v = A[i];
    for(j=i-1;j>=0;j--){
        if(A[j]>v) A[j+1] = A[j];
        else break;
    }
    A[j+1] = v;
    for(k=0;k<n-1;k++){ 
        printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);
}
return 0;
}
    
    

