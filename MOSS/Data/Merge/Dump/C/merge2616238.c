#include <stdio.h>
#include <math.h>
#define N 1000000


int n, s[N], x=0;

void merge(int, int, int);
void mergeSort(int, int);
int main()
{

int i;

scanf("%d",&n);

for(i=0; i<n; i++)

scanf("%d",&s[i]);

mergeSort(0,n);

for(i=0;i<n;i++){
   printf("%d", s[i]);

    if(i!=n-1) printf(" ");
  }

  printf("\n%d\n", x);

  return 0;
}

void merge(int left, int mid, int right)
{
  int n1, n2, i, j, k, L[N], R[N];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0; i<=n1-1; i++)
    L[i] = s[left + i];
  for(i=0; i<=n2-1; i++)
    R[i] = s[mid + i];
    L[n1] = INFINITY;
    R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k=left; k<=right-1; k++)
    if(L[i] <= R[j]){
     s[k] = L[i];
      i = i + 1;
      x++;
    } else {
      s[k] = R[j];
      j = j + 1;
      x++;
    }
}
void mergeSort(int left, int right)
{
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
   }
}
