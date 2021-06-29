#include<stdio.h>
 
int LinearSearch(int *,int);
int n,q;
 
int main(){
  int S[10000];
  int T[500];
  int i,a,c=0;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d ",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    a = LinearSearch(&S[0],T[i]);
    c += a;
  }
 
  
  printf("%d\n",c);
 
  return 0;
}
 
int LinearSearch(int * A, int key){
  int i;
 
  for(i=0;i<n;i++){
    if(A[i]==key) return 1;
  }
    return 0;
}
