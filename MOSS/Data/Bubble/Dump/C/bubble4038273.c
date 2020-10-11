#include<stdio.h>
#define N 100

void bubble(int *,int);

int main(){

  int i,n,array[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&array[i]);


  bubble(array,n);

  return 0;
}

void bubble(int A[],int n){
  int i,j,cnt=0,tmp,flag;

  flag=1;
  while(flag==1){
    flag=0;
    for(i=0;i<n;i++){
      for(j=n-1;j>i;j--){
	if(A[j]<A[j-1]){
	  tmp=A[j];
	  A[j]=A[j-1];
	  A[j-1]=tmp;
	  cnt++;
	  flag=1;
	}
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cnt);
}

