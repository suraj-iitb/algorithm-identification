#include<stdio.h>
void bubble(int A[], int n){
  int i =0,k=0,j=0,l=0;

  for( i =0;i <= n-1;i++){
    for(j = n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	l++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>=1)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",l);

}

int main(){
  int i,j,n,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubble(A,n);
  return 0;
}
