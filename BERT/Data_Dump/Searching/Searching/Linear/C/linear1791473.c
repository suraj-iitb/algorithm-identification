#include<stdio.h>
int LinearSearch(int);
int N,A[10000];
int main(){
  int i,M,key,l=0,c;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  scanf("%d",&M);
  for(i=0;i<M;i++){
    scanf("%d",&key);
    c=LinearSearch(key);
    if(c>=0 && c<=10000)
      l++;
  }
  printf("%d\n",l);
  return 0;
}

int LinearSearch(int key){
  int i;
  for(i=0;i<N-1;i++){
    if(A[i]==key) return i;
  }
  if(A[N-1]!=key) return -1;
}
