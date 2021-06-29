
#include <stdio.h>
int main (){

  int A[100],ans=0,a,b,i,j,minj;

  scanf("%d",&a);
  for(i=0;i<a;i++) scanf("%d",&A[i]);


  for(i=0;i<a;i++){
    minj=i;
    for(j=i;j<a;j++){
      if(j!=minj&&A[j]<A[minj])
          minj=j;
    }
    if(&A[i]!=&A[minj]){
       b=A[i];
       A[i]=A[minj];
       A[minj]=b;
       ans++;
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
