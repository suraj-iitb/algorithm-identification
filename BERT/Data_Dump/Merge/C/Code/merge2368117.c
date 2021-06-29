#include<stdio.h>
#define MAX 500000
#define SENTINEL 1000000000
int  A[MAX];
int count = 0 ;

void Merge(int left, int mid, int right)
{
    int n1, n2;
    int i, j, k;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1+1],  R[n2+1];
 
    for (i = 0; i < n1; i++){
    L[i] = A[left+i];
    }
   
    for (i = 0; i < n2; i++){
    R[i] = A[mid+i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{ 
            A[k] = R[j];
            j++;
        }
    }
}

void Merge_Sort(int left, int right)
{
    int mid; 
    if(left+1 < right){ 
        mid = (left + right)/2;
        Merge_Sort(left, mid);
        Merge_Sort(mid, right);
        Merge(left, mid, right);
    }
}

 
int main(){
  int n;
  int i;
  int left, mid, right;
  
  scanf("%d", &n);
 
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
 
  left = 0;
  right = n;
  Merge_Sort(left, right);
  
 for(i = 0; i < n; i++){
   printf("%d", A[i]);
   if(i != n-1)printf(" ");
 }
 printf("\n%d\n", count);
 return 0;
}
