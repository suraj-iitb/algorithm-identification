#include <stdio.h>
int main (){

  int A[100],ans=0,a,b,i,j,flag=1;

  scanf("%d",&a);
  for(i=0;i<a;i++) scanf("%d",&A[i]);

  while(flag){
      flag=0;
      for(j=a-1;j>0;j--){
          if(A[j]<A[j-1]){
            b=A[j];
            A[j]=A[j-1];
            A[j-1]=b;
            flag=1;
            ans++;
          }
       }
  }
  for(i=0;i<a;i++){
    printf("%d",A[i]);
    if(i<a-1) printf(" ");
    else printf("\n");
  }

  printf("%d\n",ans);
  return 0;
}


