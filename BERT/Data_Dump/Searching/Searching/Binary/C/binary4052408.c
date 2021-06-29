#include <stdio.h>
int binarySearch(int n, int key, int A[]){
  int i, left = 0, right = n, mid;
  while(left < right){
    mid = ((left + right)/2);
    if(A[mid] == key)return 1;
    else if(key < A[mid])right = mid;
    else left = (mid + 1);
  }
  return 0;

}

int main(){
  int i, n, q, key, sum = 0;
  int S[100000];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&key);
    sum += binarySearch(n, key, S);
  }
 
  printf("%d\n",sum);


  return 0;
}

