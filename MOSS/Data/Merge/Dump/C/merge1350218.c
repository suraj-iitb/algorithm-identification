#include <stdlib.h>
#define INFINITY 1000000001

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int nn=0;

main(){
  int n, *arryA, i;

  scanf("%d", &n);
  arryA = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++) scanf("%d", arryA+i);

  mergeSort(arryA, 0, n);
  for(i=0; i<n-1; i++) printf("%d ", arryA[i]);
  printf("%d\n%d\n", arryA[i], nn);
 
  free(arryA);
  return 0;
}

void merge(int *arryA, int left, int mid, int right){
  int n1, n2, i, j, k, *arryL, *arryR;

  n1 = mid - left;
  n2 = right - mid;

  arryL = (int *)malloc(sizeof(int)*(n1 + 1));
  arryR = (int *)malloc(sizeof(int)*(n2 + 1));
  for(i=0; i<n1; i++) arryL[i] = arryA[left+i];
  for(i=0; i<n2; i++) arryR[i] = arryA[mid+i];
  arryL[n1] = INFINITY;
  arryR[n2] = INFINITY;

  /* printf("**merge(%d, %d, %d) n(L)=%d\n", left, mid, right, n1);
  for(i=0; i<(n1+1); i++) printf("%d ", arryL[i]);
  printf("\n");
  printf("**merge(%d, %d, %d) n(R)=%d\n", left, mid, right, n2);
  for(i=0; i<(n2+1); i++) printf("%d ", arryR[i]);
  printf("\n\n");*/

  i=0;//L
  j=0;//R

  for(k=left; k<right; k++){
    nn++;
    if(arryL[i] <= arryR[j]){
      arryA[k] = arryL[i++];
    }
    else
      arryA[k] = arryR[j++];
  }

  free(arryL);
  free(arryR);
}

void mergeSort(int *arryA, int left, int right){
  int mid;

  if(left+1 < right){
    mid = (right + left) / 2;
    mergeSort(arryA, left, mid);
    mergeSort(arryA, mid, right);
    merge(arryA, left, mid, right);
  }
}
