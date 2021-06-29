#include <stdio.h>
int main(){

  int A[1000],key,i,j,a,b;

  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  for(b=0;b<a;b++){
    printf("%d",A[b]);
    if(b<a-1) printf(" ");
    else printf("\n");
  }
  for (i=1;i<a;i++){
      key=A[i];
      j=i-1;
      while(j>=0&&A[j]>key){
           A[j+1]=A[j];
           j--;
       }
      A[j+1]=key;
      for(b=0;b<a;b++){
        printf("%d",A[b]);
        if(b<a-1) printf(" ");
        else printf("\n");
      }
  }

  return 0;
}



