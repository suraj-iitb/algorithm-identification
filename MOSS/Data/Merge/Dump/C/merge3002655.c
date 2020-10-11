#include<stdio.h>
#define Max 500000
#define term 2000000000

int Left[(Max/2)+2], Right[(Max/2)+2];
int c=0;


void merge(int e[], int n, int left, int mid, int right){
  int i,j,k;

  int x = (mid-left);
  int y = (right-mid);

  for ( i=0; i<x; i++ )
   Left[i] = e[left+i];
  for ( i=0; i<y; i++ )
   Right[i] = e[mid+i];

  Left[x]= Right[y] = term;
  i = j = 0;
  for ( k=left; k<right; k++){
    c++;
    if ( Left[i]<=Right[j] ){
      e[k] = Left[i++];
    } else {
      e[k] = Right[j++];
    }
  }
}

void mergeSort(int e[], int n, int left, int right ){
  int mid;
  if ( left+1<right ){
    mid=(left + right)/2;
    mergeSort(e, n, left, mid);
    mergeSort(e, n, mid, right);
    merge(e, n, left, mid, right);
  }
}

int main(){
  int e[Max], n, i;
  scanf("%d", &n);
  for ( i=0; i<n; i++) {
    scanf("%d", &e[i]);
    if (e[i]>=term ){
      return 1;
    }
  }
  mergeSort(e,n,0,n);

  for ( i=0; i<n; i++) {
    if ( i !=0 ) 
    printf(" ");

    printf("%d", e[i]);
    }
  printf("\n");

  printf("%d\n", c);


  return 0;
}


