#include <stdio.h>

int main(){
  int flag=1,i,j,n,a[100],tmp,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	cnt++;
      }
    }
}
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",cnt);
  return 0;
}

