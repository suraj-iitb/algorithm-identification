#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000000001

int pertition(int*, char*, int, int);
void quickSort(int*, char*,int, int);
int check(int,int*, char*, int*, char*);
void merge(int *, char *, int, int, int);
void mergeSort(int *, char *, int, int);

main(){
  int n, i, r, *Ad, *cpyAd;
  char *Ac, *cpyAc;

  scanf("%d", &n);
  Ad = malloc(sizeof(int)*n);
  Ac = malloc(sizeof(char)*n);
  cpyAd = malloc(sizeof(int)*n);
  cpyAc = malloc(sizeof(char)*n);

  for(i=0; i<n; i++){
    scanf(" %c", Ac+i);
    scanf("%d", Ad+i);
    cpyAc[i] = Ac[i];
    cpyAd[i] = Ad[i];
    //printf("i=%d\n", i);
  }

  quickSort(Ad, Ac, 0, n-1);
  
  if(check(n, Ad, Ac, cpyAd, cpyAc)) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++){
    printf("%c %d\n", Ac[i], Ad[i]);
  }

  free(Ad);
  free(Ac);
  free(cpyAd);
  free(cpyAc);
  return 0;
}

void quickSort(int *A, char *A2, int p, int r){
  int q;

  if(p < r){
    q = partition(A, A2, p, r);
    quickSort(A, A2, p, q-1);
    quickSort(A, A2, q+1, r);
  }
}

int partition(int *A, char *A2, int p, int r){
  int x = A[r];
  int i = p-1;
  int j, tmp;
  char tmp2;

  for(j=p; j<r; j++){
    if(A[j] <= x){
      i = i+1;
      tmp = A[i];
      tmp2 = A2[i];
      A[i] = A[j];
      A[j] = tmp;
      A2[i] = A2[j];
      A2[j] = tmp2;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  tmp2 = A2[i+1];
  A2[i+1] = A2[r];
  A2[r] = tmp2;

  return i+1;
}

int check(int n, int *Ad, char *Ac, int *oriAd, char *oriAc){
// 安定なソートであるMergeSortの結果と比較する
// 安定 : 1
// 安定でない : 0
  int i;

mergeSort(oriAd, oriAc, 0, n);

#ifdef DEBUG
  printf("\n****** MergeSort ******\n");
  for(i=0; i<n; i++) printf("%c %d\n", oriAc[i], oriAd[i]);
  printf("\n***********************\n");
#endif

  //アルファベットについて一致するか判定
  for(i=0; i<n; i++){
    if(/*QuickSort*/Ac[i] != /*MergeSort*/oriAc[i]) return 0;
  }
  return 1;
}

void merge(int *arryA, char *arryB, int left, int mid, int right){
  int n1, n2, i, j, k, *arryL, *arryR;
  char *arryLc, *arryRc;

  n1 = mid - left;
  n2 = right - mid;

  arryL = (int *)malloc(sizeof(int)*(n1 + 1));
  arryR = (int *)malloc(sizeof(int)*(n2 + 1));
  arryLc = (char *)malloc(sizeof(char)*(n1 + 1));
  arryRc = (char *)malloc(sizeof(char)*(n2 + 1));
  for(i=0; i<n1; i++){
    arryL[i] = arryA[left+i];
    arryLc[i] = arryB[left+i];
    //printf("++ arrLc[%d] = %c\n", i, arryB[left+i]);
  }
  for(i=0; i<n2; i++){
    arryR[i] = arryA[mid+i];
    arryRc[i] = arryB[mid+i];
    //printf("++ arrRc[%d] = %c\n", i, arryB[mid+i]);
  }
  arryL[n1] = INFINITY;
  arryR[n2] = INFINITY;

  i=0;//L
  j=0;//R

  for(k=left; k<right; k++){
    if(arryL[i] <= arryR[j]){
      arryA[k] = arryL[i];
      arryB[k] = arryLc[i];
      i++;
    }
    else{
      arryA[k] = arryR[j];
      arryB[k] = arryRc[j];
      j++;
    }
  }

  free(arryL);
  free(arryR);
  free(arryLc);
  free(arryRc);
}

void mergeSort(int *arryA, char *arryB,int left, int right){
  int mid;

  if(left+1 < right){
    mid = (right + left) / 2;
    mergeSort(arryA, arryB, left, mid);
    mergeSort(arryA, arryB, mid, right);
    merge(arryA, arryB, left, mid, right);
  }
}
