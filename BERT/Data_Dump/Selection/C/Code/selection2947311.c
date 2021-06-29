#include<stdio.h>
int main()
{
  int n,i,k,j,st,ex=0,ss=1;;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    int minj=i;
    for(j=i;j<n;j++){      
      if(a[j]<a[minj]){
	minj=j;
	if(ss==1){
	  ex++;
	  ss=0;
	}
      }
    }
      ss=1;
      st=a[minj];
      a[minj]=a[i];
      a[i]=st;
  }
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i!=n-1)printf(" ");
    }
    printf("\n");
    printf("%d\n",ex);
  return 0;
}
