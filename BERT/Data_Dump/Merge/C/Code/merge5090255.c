#include<stdio.h>
#include<stdlib.h>

/* マージソート */
void merge_sort (int*,int,int); 

void merge (int*,int,int,int);

int cnt = 0;

#define MAX 500000
 

int main () {
  int A[500000];
  int i,n;

  scanf("%d",&n);

  if(n > 500000)exit(0);

  for (i = 0; i < n; i++) { 

      scanf("%d",&A[i]);
   }
  
  //printf("test\n");

  merge_sort(A, 0, n-1);

  //printf("test\n");

  
  for (i = 0; i < n; i++) { 

      if(i == n-1){
          printf("%d\n",A[i]);
      }
      else {
        printf("%d ", A[i]);
   } 
   
   }

   printf("%d\n",cnt);
 

  return 0;
}

void merge_sort (int A[], int left, int right) {
  int i, j, k, mid;
    
  if (left < right) {
    mid = (left + right)/2; 
    merge_sort(A, left, mid);  
    merge_sort(A, mid+1, right); 

     //printf("test\n");

    merge(A,mid,left,right);
    
  }
}

void merge(int A[],int mid,int left,int right){

    int B[500000],j,i,k,n1,n2;

    int L[500000],R[500000];

    /*n1 = mid - left;

    n2 = right - mid;

    for(i = 0;i < n1;i++){

      L[i] = A[left + i];
    }

    for(i = 0;i < n2;i++){

      R[i] = A[mid + i];
    }

    L[n1] = MAX;
    R[n2] = MAX;

    i = 0;

    j = 0;

    for(k = left;k < right;k++){

      cnt++;

      if(L[i] <= R[j]){
        A[k] = L[i];
        i = i + 1;

      }

      else{
        A[k] = R[j];

        j = j + 1;
      }
    }*/

    for (i = mid; i >= left; i--) { 

        B[i] = A[i]; 

        } 
     for (j = mid + 1; j <= right; j++) {

      B[right - (j - (mid+1))] = A[j];

      }
    i = left; j = right;
    for (k = left; k <= right; k++) {
        cnt++;
      if (B[i] < B[j]) { 
          A[k] = B[i++];
  
          }
      else  { 
          A[k] = B[j--];
       
          }
    }
}
