#include<stdio.h>

  int A[100000];
int N;

 int binarysearch(int key){
  int left = 0;
  int right = N;
  int mid;

  while(left<right){
    mid = (left + right)/2;
      if(A[mid] == key){
        return 1;/*keyを発見*/
      }else if(key<A[mid]){
        right = mid;/*前半*/
      }else{
        left = mid +1;/*後半*/
      }

  }
  return 0;
 }

int main(){
  int i,M,key,num = 0;
  int k = 0;


  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&M);

  for(i = 0; i<M; i++){
    scanf("%d",&key);
    if(binarysearch(key)==1){
      num++;
      }
    }

  printf("%d\n",num);

  return 0;
}

