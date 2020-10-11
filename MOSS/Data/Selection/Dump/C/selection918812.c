#include <stdio.h>

static const int N = 100;
int c=0;

void SelectionSort(int A[],int n){
  int i,j,k,temp,mini;

  for(i=0;i<n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    if(A[i]!=A[mini]){
        /*swap*/
	temp=A[i];
	A[i]=A[mini];
	A[mini]=temp;
	c++;
    }
  }
}

main(){
  int i,j,n;
  int A[N+1];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  SelectionSort(A,n);

  for(j=1;j<=n;j++){
    if(j>1) printf(" ");
    printf("%d",A[j-1]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
