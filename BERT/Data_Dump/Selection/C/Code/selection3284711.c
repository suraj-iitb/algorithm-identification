#include <stdio.h>

int selection(int a[],int b)
{
  int l,m,n,o,p=0;
  for(l=0;l<b-1;l++){
    m=l;
    for(n=l;n<b;n++){
      if(a[n]<a[m]){
	m=n;
      }
    }
    o=a[l];
    a[l]=a[m];
    a[m]=o;
    if(l!=m){
      p++;
    }
  }
  return p;
}

  int main(){
  int A[100],i,j,k;
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&A[i]);
  }
  j=selection(A, k);
  for(i=0;i<k;i++){
    if(i>0){
      printf(" ");
	}
      printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",j);
  return 0;
}
  

