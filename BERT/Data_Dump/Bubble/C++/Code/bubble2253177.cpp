#include <stdio.h>
int main(){
  int n,i,I;
  scanf("%d",&n);
  int a[n];
  int tmp,count =0 ;
  for(i = 0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int j;
  for(i = 0;i<n-1;i++){
    for(j = n-1;j >= i+1;j--){
      if(a[j] < a[j-1]){
	count ++;
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1]= tmp;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}
  
	
