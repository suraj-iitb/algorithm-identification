#include<stdio.h>
#define MAX 100000
#define INFINITY 1000000000
#define TRUE 1
#define FALSE 0
typedef struct{
  char mark;
  int num;
}trump;
int partition(trump *, int, int);
void quicksort(trump *, int, int);
void merge(trump *, int, int, int);
void mergeSort(trump *, int, int);
int isStable(trump *, trump *, int);

int main(){
  int i,n;
  trump card[MAX],data[MAX];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf(" %c%d",&card[i].mark,&card[i].num);
    data[i] = card[i];
  }
  mergeSort(data,0,n);
  quicksort(card, 0, n-1);
  if(isStable(data, card, n) == TRUE) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++){
    printf("%c %d\n",card[i].mark,card[i].num);
  }
  return 0;
}

int partition(trump *card, int p, int r){
  int i,j,x;
  trump temp;
  x = card[r].num;
  i = p-1;
  for(j=p; j<r; j++){
    if(card[j].num <= x){
      i = i+1;
      temp = card[i];
      card[i] = card[j];
      card[j] = temp;

    }
  }
  temp = card[i+1];
  card[i+1] = card[r];
  card[r] = temp;

  return i+1;
}

void quicksort(trump *card, int p, int r){
  int q;
  if(p<r){
    q = partition(card, p, r);
    quicksort(card, p, q-1);
    quicksort(card, q+1, r);
  }
}

void merge(trump *S, int left, int mid, int right){
  int i,j,k;
  trump L[MAX],R[MAX];
  int n1 = mid-left;
  int n2 = right-mid;

  for(i=0; i<n1; i++){
    L[i] = S[left+i];
  }
  for(i=0; i<n2; i++){
    R[i] = S[mid+i];
  }
  L[n1].num = INFINITY;
  R[n2].num = INFINITY;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    if(L[i].num <= R[j].num){
      S[k] = L[i];
      i = i+1;
    }
    else{
      S[k] = R[j];
      j = j+1;
    }
  }  
  
}

void mergeSort(trump *S, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S,left,mid,right);
  }

}

int isStable(trump *data, trump *card, int n){
  int i;
    for(i=0; i<n; i++){
        if(data[i].num != card[i].num || data[i].mark != card[i].mark) return FALSE;
    }
    return TRUE;
}

