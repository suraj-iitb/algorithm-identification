#include<stdio.h>

int Selection(int *,int);
void change(int *,int);

int main(){
  int N,i,j,cnt;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  cnt = Selection(A,N);
  change(A,N);
  printf("%d\n",cnt);
}

int Selection(int A[],int n){
  int i,j,change,cnt=0,min;
  
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i;j<n;j++){
      if(A[j] < A[min]) min = j;
    }
    change = A[i];
    A[i] = A[min];
    A[min] = change;
    if(i != min) cnt++;
  }
  return cnt;
}

void change(int A[], int n){
  int i;
  for(i=0;i<n;i++){
    if( i>0 ) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

