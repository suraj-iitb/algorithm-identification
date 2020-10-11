#include <stdio.h>

int cnt;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;

    int n1 = m - l + 1;  // number of elements in first subarray
    int n2 = r - m;      // number of elements in second subarray

    // create temporary subarrays
    int L[n1];  // array[l..m]
    int R[n2];  // array[m+1..r]

    // copy data to subarrays L and R 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // merge the two arrays
    i = 0;    // index of L
    j = 0;    // index of R
    k = l;    // index of merged array
   
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
	cnt++;
	
    }
     
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
	cnt++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
	cnt++;
    }
}

void mergeSort(int array[], int l, int r) {

    if (l < r) {
        // avoids overflow for large l and h
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }

}


int main (void) {

    int n,i,S[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n-1);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1) printf(" ");
    if(i == n-1) printf("\n");
  }
  printf("%d\n",cnt);

  return 0;
}

