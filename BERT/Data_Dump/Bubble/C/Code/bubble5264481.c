#include<stdio.h>
#define N 101

int n;
int A[N];
int cnt=0;


void bubble(){

  int i,j;
  int t;


  for(i=0;i<n;i++){
    for(j=n-1;i<j;j--){
      if(A[j]<A[j-1]){
        t=A[j];
        A[j]=A[j-1];
        A[j-1]=t;
        cnt++;
      }
    }
  }
}




int main(){

  int i,j;

  scanf("%d",&n);


  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }


  bubble();


  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");
  printf("%d\n",cnt);













  return 0;
}

