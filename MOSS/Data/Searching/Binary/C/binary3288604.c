#include<stdio.h>
int binsearch(int, int [], int);

int main(){
  int n, i, q, c = 0;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  
  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
    if(binsearch(n, S, T[i]) == 1) c += 1;
  }

  printf("%d\n", c);

  return 0;
}

int binsearch(int n, int A[], int key){
  int left = 0, right = n;
  int mid;

  while(left < right){
    mid = (left + right) / 2;

    if(A[mid] > key) right = mid;
    if(A[mid] < key) left = mid + 1;
    if(A[mid] == key) return 1;

  }
  return 0;
}
				       


  

