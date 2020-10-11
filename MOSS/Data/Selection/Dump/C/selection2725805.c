#include <stdio.h>
int main(){
  int min=0;
  int i, j;
  int N;
  int tmp;
  scanf("%d", &N);
  int A[N];
  for(i=0; i<N; ++i){
	scanf("%d", &A[i]);
  }
  int index;
  int count=0;
  for(i=0; i<(N-1); ++i){
	tmp=A[i];
	min=A[i];
	for(j=i+1; j<N; ++j){
	  if(min>A[j]){
		min=A[j];
		index=j;
	  }
	}
	if(tmp!=min){
	  A[i]=min;
	  A[index]=tmp;
	  ++count;
	}
  }
  for(i=0; i<N; ++i){
	printf("%d", A[i]);
	if(i<(N-1))
	  printf(" ");
}
  printf("\n");
  printf("%d\n", count);
  return 0;
}

