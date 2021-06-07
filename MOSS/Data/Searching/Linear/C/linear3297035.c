#include <stdio.h>
int search(int A[], int a, int key);
  
int main(){
  int i,j,k,key,sum=0,A[10000+1];
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&key);
    if(search(A,j,key)){
      sum++;
	}
  }
    printf("%d\n",sum);
    return 0;
  }
int search(int A[], int a, int key){
  int x=0;
  A[a]=key;
  while(A[x]!=key) x++;
  return x!=a;
}

