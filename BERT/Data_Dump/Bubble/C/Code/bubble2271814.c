#include <stdio.h>
int main(){
  int i,j,a[100],n,tmp,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	cnt++;
      }
    }
  }
    
  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j!=n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",cnt);
  return 0;
}
