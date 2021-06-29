#include<stdio.h>

int S[100000];
int N;

int binarySerch(int);

int main(){
int q, T[50000], i, c = 0;

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T[i]);
    if(1 == binarySerch(T[i])){
      c++;
    }
  }
  printf("%d\n",c);
  return 0;

}

int binarySerch(int key){
  int mid;
  int left = 0;
  int right = N;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key)
      return 1;
    else if(key < S[mid])
      right = mid;
    else 
      left = mid + 1;
  }
  return 0;
}
