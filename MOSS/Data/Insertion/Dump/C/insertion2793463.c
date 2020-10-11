/*16D8104007J 1-A　兼弘真帆　*/
#include<stdio.h>

void insertionSort(int A[],int N);

int main(){
  int N;
  // printf("長さN:"); 
  scanf("%d",&N);
  int A[N];
  int i;

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  insertionSort(A,N);
  return 0;

}

void insertionSort(int A[],int N){
  int i,j,v,n;
  for(n=0;n<N;n++){
    printf("%d",A[n]);
    if(n!=N-1){
      putchar(' ');
    }
  }
  
  putchar('\n');

  for(i=1;i<N;i++){
    // printf("test2\n");
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      // printf("test1\n");
    }
    A[j+1]=v;
    for(n=0;n<N;n++){
      if(n!=N-1){
	printf("%d ",A[n]);
      }else{
	printf("%d\n",A[n]);
      }
    }
  }
}

