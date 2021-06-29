#include<stdio.h>

int main(){

int flag, j, g, tmp, N;
int count=0;

scanf("%d",&N);

int A[N];

for(g=0;g<N;g++){
     scanf("%d",&A[g]);
}

flag=1;

while(flag){
          flag=0;
          for(j=N-1;j>=1;j--){
             if(A[j]<A[j-1]){
                   tmp=A[j];
                   A[j]=A[j-1];
                   A[j-1]=tmp;
                   flag=1;
                   count++;
            }
       }
 }

for(g=0;g<N;g++){
      printf("%d",A[g]);
      if(g<N-1)printf(" ");
}
printf("\n%d\n",count);


return 0;
}
