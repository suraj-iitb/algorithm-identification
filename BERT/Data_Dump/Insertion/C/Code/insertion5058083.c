#include<stdio.h>

int main(){

int i, j, v, N,g;

scanf("%d", &N);

int A[N];

for(i=0;i<N;i++){
     scanf("%d",&A[i]);
}

for(g=0;g<N;g++){
     printf("%d",A[g]);
    if(g<N-1)printf(" ");
 }
printf("\n");

for(i=1;i<N;i++){
      v = A[i];
      j = i - 1;
      while(j>=0&&A[j]>v){
               A[j+1] = A[j];
               j--;
               A[j+1] = v;
   }
for(g=0;g<N;g++){
     printf("%d",A[g]);
     if(g<N-1)printf(" ");
 }
printf("\n");
}

return 0;
}
