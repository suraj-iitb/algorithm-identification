#include <stdio.h>
 
#define N 500000
#define S 1000000000
 
int merge(int *, int, int, int);
void mergeSort(int *, int, int);
 
int n, s[N], tmp[N], x[N];
int  count = 0;
 
int main(){
    int i, x;
 
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    
    mergeSort(s, 0, n-1);

    for(i = 0; i < n-1; i++){
        printf("%d ", s[i]);
    }
    printf("%d\n", s[n-1]);
    printf("%d\n", count);

    return 0;

}
 
void mergeSort(int A[], int left, int right){
    int mid, i, j, k;
    
    if(left >= right) return;

    mid = (left + right) / 2;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    
    for(i = left; i <= mid; i++){
        tmp[i] = A[i];
        }
 
    for(i = mid + 1, j = right; i <= right; i++, j--){
        tmp[i] = A[j];
        }
        
    i = left;
    j = right;
 
    for(k = left; k <= right; k++){
      if(tmp[i] <= tmp[j]) A[k] = tmp[i++];
      else A[k] = tmp[j--];
      count++;
    }
}
