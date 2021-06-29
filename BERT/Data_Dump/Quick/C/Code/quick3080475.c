#include<stdio.h>
#define N 100000

void quickSort(int, int);
int partition(int, int);
int check(int);

int A[N],in1[N];
char C[N],in2[N];

int main(){
  int n,i,a,b,j,flag = 1;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf(" %c %d",&C[i],&A[i]);
    in2[i] = C[i];
    in1[i] = A[i];
  }
  quickSort(0,n-1);
  
  if(check(n)==0) printf("Not stable\n");
  else printf("Stable\n");
  
  for(i=0 ; i<n ; i++){
    printf("%c %d\n",C[i],A[i]);
  }
  
  return 0;
}

int check(int n){
  int i,j,a,b;
  for(i=1;i<n;i++){
    if(A[i-1] == A[i]){
      for(j=0;j<n;j++){
        if(A[i-1] == in1[j] && C[i-1] == in2[j]) a = j;
        if(A[i] == in1[j] && C[i] == in2[j]) b = j;
      }
      if(a > b) return 0;
    }
  }
  return 1;
}


void quickSort(int p,int r){
  int q;
  if(p < r){
    q = partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}

int partition(int p,int r){
  int x,i,j,a;
  char c;
  x = A[r];
  i = p-1;
  for(j=p ; j<r ; j++){
    if(A[j] <= x){
      i++;
      a = A[i];
      A[i] = A[j];
      A[j] = a;
      c = C[i];
      C[i] = C[j];
      C[j] = c;
    }
  }
    a = A[i+1];
    A[i+1] = A[r];
    A[r] = a;
    c = C[i+1];
    C[i+1] = C[r];
    C[r] = c;
    return i+1;
}

