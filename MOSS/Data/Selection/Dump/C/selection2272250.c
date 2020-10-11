#include<stdio.h>
int main(){
  int j,i,mini,n,a[100],v,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i = 0;i<=n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[mini]){
	mini = j;
      }
    }
      if(i!=mini){
      	v = a[i];
	a[i]=a[mini];
	a[mini]=v;
	cnt++;
      }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}
