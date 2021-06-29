#include<stdio.h>
#define N 100
int main(){

  int num[N],i,j,l=1,n,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  i=0;
  while(l){
    l=0;
    for(j=1;j<n;j++){
      if(num[j]<num[j-1]){
	v=num[j];
	num[j]=num[j-1];
	num[j-1]=v;
	l++;
	i++;
      }
    }
  }
  for(j=0;j<n-1;j++) printf("%d ",num[j]);
  printf("%d\n%d\n",num[n-1],i);
  return 0;
}

