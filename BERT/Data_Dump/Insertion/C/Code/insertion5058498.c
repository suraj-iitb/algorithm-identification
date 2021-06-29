#include <stdio.h> 
 void insertionSort(int *, int);
int main(){
    int N,i=0;
    int A[100];
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    insertionSort(A,N);
    return 0;
}
void insertionSort(int *data,int N){
  int i=0,j=0,k=0,tmp=0;
for(k=0;k<N;k++){
    if(k!=N-1)printf("%d ",data[k]);
    else printf("%d\n",data[k]);
    }
  for (i = 1; i < N; i++) {

    tmp = data[i];
    if (data[i - 1] > tmp) {
      j = i;
      do {
	data[j] = data[j - 1];
	j--;
      } while (j > 0 && data[j - 1] > tmp);
      data[j] = tmp;
    }
    for(k=0;k<N;k++){
        if(k!=N-1)printf("%d ",data[k]);
        else printf("%d\n",data[k]);
        }
  }
}
