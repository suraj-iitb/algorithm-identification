
#include<stdio.h>

int main(){

int minj, j, g, tmp, i, N;
int count=0;

scanf("%d",&N);

int A[N];

for(g=0;g<N;g++){
     scanf("%d",&A[g]);
}

for(i=0;i<N;i++){
     minj=i;
     for(j=i;j<N;j++){
           if(A[j]<A[minj]){
             minj=j;
             }
           }
            if(minj!=i){
             tmp=A[i];
             A[i]=A[minj];
             A[minj]=tmp;
             count++;
            }     
}

for(g=0;g<N;g++){
      printf("%d",A[g]);
      if(g<N-1)printf(" ");
}
printf("\n%d\n",count);


return 0;
}
