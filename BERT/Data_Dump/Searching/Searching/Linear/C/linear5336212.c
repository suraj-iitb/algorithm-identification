#include<stdio.h>
#define N 10001



int n;
int A[N];
int q;
int cnt=0;




void liner(int x){

  int i;

  for(i=0;i<n;i++){
    if(A[i]==x){
      cnt++;
      break;
    }
  }
}


int main(){

  int i;
  int x;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&x);
    liner(x);
  }

  printf("%d\n",cnt);













  return 0;
}

