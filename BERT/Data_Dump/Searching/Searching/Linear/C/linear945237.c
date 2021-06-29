#include <stdio.h>

int main(){

  int n,m,i,a[10000],b[10000],k,j;
  m=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&b[i]);
  }


  for(j=0;j<k;j++){

    for(i=0;i<n;i++){

      if(a[i]==b[j]){
	m++;
	break;
      }
    }
  }
  printf("%d\n",m);
  return 0;
}
