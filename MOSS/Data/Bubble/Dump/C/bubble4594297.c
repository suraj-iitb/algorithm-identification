#include<stdio.h>
int main()
{
  int a,b[100],i,j,n=0,m;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<a-1;i++){
    for(j=a-1;j>i;j--){
      if(b[j]<b[j-1]){
	m=b[j];
	b[j]=b[j-1];
	b[j-1]=m;
	n++;
      }
    }
  }
  for(i=0;i<a-1;i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);
  printf("%d\n",n);
  return 0;
}

