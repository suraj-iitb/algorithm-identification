/* 学籍番号 17D8101029G 石塚 博之 ID: mcatpolo 言語:C */
#include <stdio.h>
#include <math.h>
#define N 500000

long c = 0;

long A[N];

void merge(int left, int mid, int right){
    long L[N/2+1], R[N/2+1];
    int n1, n2, i, j, k;

    n1 = mid - left;
    n2 = right - mid;

   for(i=0; i<n1; i++){
       L[i] = A[left+i];
   }

   for(i=0; i<n2; i++){
       R[i] = A[mid + i];
   }

   L[n1] = (long)INFINITY;
   R[n2] = (long)INFINITY;

   i=0;
   j=0;

   for(k=left; k<right; k++){
       c++;
       if(L[i] <= R[j]) {
           A[k] = L[i];
           i++;
       }
       else {
           A[k] = R[j];
           j++;
       }
   }

}

void mergeSort(int left, int right){
    int mid;
    if(left+1<right){
        mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main(void){
    int i, n;

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }

   mergeSort(0, n);

   for(int i=0; i<n; i++){
       if(i!=n-1){
           printf("%d ", A[i]);
       }
       else
       {
           printf("%d\n", A[i]);
       }
       
   }

   printf("%d\n", c);

   return 0;
}
