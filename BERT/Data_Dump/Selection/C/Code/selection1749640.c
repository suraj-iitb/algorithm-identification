#include<stdio.h>
int main(){

  int i,j,min,max,n,a[100],esc,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  if(n==1) printf("%d\n0\n",a[0]);
  else{
    for(i=0;i<n-1;i++){
      min=i;
      for(j=i+1;j<n;j++){
	if(a[j]<a[min]){
	  min=j;
	}
      }
      if(i==min) continue;
      esc=a[i];
      a[i]=a[min];
      a[min]=esc;
      count++;
    }
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i==n-1) break;
      printf(" ");
    }
    printf("\n%d\n",count);
  }
  return 0;
}
