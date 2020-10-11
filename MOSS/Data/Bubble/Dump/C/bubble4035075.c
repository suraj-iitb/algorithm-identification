#include <stdio.h>
#define N 100

int main (){
  int a,i,n,j,k,l,box,m=0;
  int b[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    b[i]=a;
  }
  
    for(j=0;j<n;j++){
      for(k=n-1;k>=j+1;k--){
	if(b[k]<b[k-1]){
	  box=b[k];
	  b[k]=b[k-1];
	  b[k-1]=box;
	  m++;
	}
      }
    }
      for(l=0;l<n-1;l++){
      printf("%d ",b[l]);
    }
    printf("%d\n",b[l]);
    printf("%d\n",m);
      return 0;
}

