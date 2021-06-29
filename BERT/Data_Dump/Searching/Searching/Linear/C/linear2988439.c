#include <stdio.h>

int count=0;
int check(int A[ ],int n,int key){
  int i=0;
  A[n]=key;
  while(i < n){
    if(A[i] == key){
      count++;
      break;
    }
    i++;
  }
}

int main(){
  int i,j,n,s[10000],q,key;

  scanf("%d",&n);
  for(i=0;i < n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i < q;i++){
    scanf("%d",&key);
    check(s,n,key);
  }

  printf("%d\n",count);

  return 0;
}



