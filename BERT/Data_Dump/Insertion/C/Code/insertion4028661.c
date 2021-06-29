#include<stdio.h>
#define N 100
//void insert(int*,int);
//void print(int*,int);
void print(int A[],int n){
  int i;

  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
void insert(int A[] ,int n){
  int i,j,v;

  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
     
    }
     A[j+1]=v;
    print(A,n);
  }

}


int main(){

  int i,n,ar[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&ar[i]);

  print(ar,n);

  insert(ar,n);

  return 0;
}

/*void insert(int A[] ,int n){
  int i,j,v;

  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
     
    }
     A[j+1]=v;
    print(A,n);
  }

}

void print(int A[],int n){
  int i;

  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
*/

