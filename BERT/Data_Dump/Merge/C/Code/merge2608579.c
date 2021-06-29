#include<stdio.h>
#define MAX 550000
void merge(int A[], int left, int mid, int right, int *c) {
   int n1, n2;
   int i, j, k;
   int L[MAX], R[MAX];

   n1 = mid - left;
   n2 = right - mid;

   for (i = 0; i < n1; ++i) {
	  L[i] = A[left + i];
   }
   for (i = 0; i < n2; ++i) {
	  R[i] = A[mid + i];
   }
   L[n1] = MAX * MAX;
   R[n2] = MAX * MAX;
   i = 0;
   j = 0;

   for (k = left; k < right; ++k) {
	  if (L[i] <= R[j]){
		 A[k] = L[i];
	     i = i + 1;
	     *c += 1;
	  }
	  else {
		 A[k] = R[j];
		 j = j + 1;
		 *c += 1;
	  }
   }
}

void mergeSort(int A[], int left, int right, int *c) {
   int mid;
   if (left + 1 < right) {
	  mid = (left + right) / 2;
	  mergeSort(A, left, mid, c);
	  mergeSort(A, mid, right, c);
	  merge(A, left, mid, right, c);
   }
}

int main()
{
   int n, i, count;
   int S[MAX];
   int *c;
   c = &count;
   i = 0;

   scanf("%d", &n);
   while (i < n) {
	  scanf("%d", &S[i]);
	  i++;
   }

   mergeSort(S, 0, n, c);

   i = 0;
   while (i < n) {
	  printf("%d", S[i]);
	  i++;
	  if (i != n)
		 putchar(' ');
   }
   putchar('\n');
   printf("%d\n", count);
   return 0;
}
