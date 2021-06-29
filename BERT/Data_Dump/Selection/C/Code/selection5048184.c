#include <stdio.h>
#define N 100
int main(){
  int A[N],i,j,n,mini,key,flag=0,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]) {
	mini=j;
	flag=1;
      }
    }
    if(flag==1){
      flag=0;
      cnt++;
    
    key=A[i];
    A[i]=A[mini];
    A[mini]=key;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",cnt);
  return 0;
}

