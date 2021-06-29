#include <stdio.h>
#define YOUSO 100000
int search(int *,int,int);

int main(){
  int n,q,S[YOUSO],key,i,j,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(S,n,key))sum++;
  }

  printf("%d\n",sum);

  return 0;
}
int search(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)i++;
  return i!=n;

}

