#include<stdio.h>
#define N 100
void swap(int *,int *);
int main(){
  int i,j,mini;
  int A[N];
  int n,flag,cnt=0;

  scanf("%d",&n);

  for(i=0; i<n; i++) scanf("%d",&A[i]);

  for(i=0; i<n-1; i++){
    mini = i;
    for(j=i,flag=0; j<n; j++){
      if(A[j]<A[mini]){
         mini = j;
         flag=1;
       }
     }
  if(flag==0) continue;
  swap(&A[i],&A[mini]);
  cnt++;
  }

  for(i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);


  return 0;
}

void swap(int *a,int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
