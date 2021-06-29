#include<stdio.h>
int main(){
  int a[109],i,j,m,s,n,c=0,d=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<n;i++){
    m=i;
    for(j=i;j<n;j++){
      if(a[j]<a[m]){
	m=j;
	d=1;
      }
    }
    if(d==1){
      s=a[i];
      a[i]=a[m];
      a[m]=s;
      c++;
      d=0;
    }
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[n-1],c);
  return 0;
}

