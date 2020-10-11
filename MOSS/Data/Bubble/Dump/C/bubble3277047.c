#include<stdio.h>



int bubblesort(int A[],int N ){
  int i,handan=1,j,n,cnt=0;
  
  for(i=0;i<N;i++){
    handan=0;
    for(j=N-1;j>=i+1;j--){
      
      if(A[j]<A[j-1]){
	n=A[j];
	A[j]=A[j-1];
	A[j-1]=n;
	handan=1;
	cnt++;
      }
    }
  }
  return cnt;
    
}


int main(){
  int n,i,cnt=0;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  cnt=bubblesort(A,n);

  for(i=0;i<n-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d",A[n-1]);

  printf("\n");
  printf("%d\n",cnt);
}

