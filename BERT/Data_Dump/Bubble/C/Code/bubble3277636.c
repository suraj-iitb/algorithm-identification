#include<stdio.h>
void swap(int *a,int *b){
  int work;
  work=*a;
  *a=*b;
  *b=work;
}

int main(){
  int i,j,n,c=0,flag;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  flag=1;
 
  while(flag){
   
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	swap(&a[j],&a[j-1]);
	flag=1;
	c++;
      }
    }
  }
 for(i=0;i<n-1;i++) printf("%d ",a[i]);
 printf("%d\n",a[n-1]);
 printf("%d\n",c);
  
  
  return 0;
}

