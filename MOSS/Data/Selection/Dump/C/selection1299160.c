#include<stdio.h>
int main()
{
  int a,b[100],i,j,n=0,m,k,mini;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<a-1;i++){
    mini=i; 
    m=b[i];
    for(j=i;j<a;j++){
      
      if(b[j]<m){
	m=b[j];
	mini=j;
      }
    }
    if(m!=b[i]){
      k=b[i];
      b[i]=b[mini];
      b[mini]=k;
      n++;
    }
  }
  for(i=0;i<a-1;i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);
  printf("%d\n",n);
  return 0;
}
