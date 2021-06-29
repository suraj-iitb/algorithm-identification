#include <stdio.h>

void change(int a[], int n){
  int i;
  for(i=0;i<n;i++){
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

int Bubble(int A[], int n){
  int flag=1,i,j,cnt=0,swap;
  
  for(i=0;flag == 1;i++){
    flag = 0;
    for(j=n-1;j >= i+1;j--){
      if(A[j] < A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
      flag = 1;
      cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int i,j,n,cnt;
  int A[100];

  scanf("%d",&n);
  
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  
  cnt = Bubble(A,n);
  change(A,n);
  printf("%d\n",cnt);
  
}


