#include <stdio.h>
#define N 10000

int linearSearch(int[],int[],int,int);

int main(){
  int n,i,a[N],b[N],key,x,q;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&b[i]);
  }

  x=linearSearch(a,b,n,q);

  if(x==0) printf("0\n");
  else printf("%d\n",x);

  return 0;
}

int linearSearch(int a[],int b[],int n,int q){
  int i,j,status=0;

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(a[j]==b[i]){
	status++;
	break;
      }
    }
  }
  return status; 
}

