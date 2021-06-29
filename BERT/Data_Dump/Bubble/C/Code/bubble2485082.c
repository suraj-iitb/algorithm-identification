#include<stdio.h>
 
static const int N = 100;
 
int main(){
  int n,i,j;
  int v;
  int count=0;
  int A[N];
 
  /*scanf data*/
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
 
  /*bubbule sort*/
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j-1]>A[j]){
    v=A[j];
    A[j]=A[j-1];
    A[j-1]=v;
    count++;
      }
    }
  }
 
  /*printf data*/
  printf("%d",A[0]);
  for(i=1;i<n;i++)printf(" %d",A[i]);
  printf("\n%d\n",count);
  return 0;
}
