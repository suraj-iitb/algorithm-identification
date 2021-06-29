#include<stdio.h>
int main(){
  int flag=1,i,j,n,a[100],v,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  i =0;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	v=a[j];
	a[j]=a[j-1];
	a[j-1]=v;
	flag=1;
	cnt++;
      }
    }
  }for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}
