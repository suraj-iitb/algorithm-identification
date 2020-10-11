#include <stdio.h>

int main(){
  
  
  int i,j,tmp,k,l,m,n,count=0;
  int data[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  
  for(k=0;k<n-1;k++){
    for(l=n-1;l>k;l--){
      if(data[l-1]>data[l]){
	tmp = data[l];
	data[l] = data[l-1];
	data[l-1] = tmp;
	count = count + 1;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
