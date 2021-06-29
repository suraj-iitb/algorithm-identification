#include <stdio.h>
#define N 100000

typedef struct card{
  int value;
  char mark;
}CARD;

int cnt = 0;

CARD QUICK[N],MERGE[N];

int part(int p,int r){
  int i;
  CARD x,tmp;
  x = QUICK[r];
  i = p-1;
  for(int j = p; j < r; j++){
    if(QUICK[j].value <= x.value) {
      i++;
      tmp = QUICK[i];
      QUICK[i] = QUICK[j];
      QUICK[j] = tmp;
    }
  }
  tmp = QUICK[i+1];
  QUICK[i+1] = QUICK[r];
  QUICK[r] = tmp;
  return i+1;
}

void quick_sort(int p,int r){
  int q;
  if(p < r){
    q = part(p,r);
    quick_sort(p,q-1);
    quick_sort(q+1,r);
  }
}

void merge(int left,int mid,int right){
  int n1,n2,i,j,k;
  CARD L[N],R[N];
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1;i++){
    L[i] = MERGE[left + i];
  }
  for(i = 0; i < n2;i++){
    R[i] = MERGE[mid + i];
  }
  L[n1].value = 999999999;
  R[n2].value = 999999999;
  i = 0;
  j = 0;
  for(k = left; k < right;k++){
    if(L[i].value <= R[j].value){
      MERGE[k] = L[i];
      i++;
      cnt++;
    }
    else {
      MERGE[k] = R[j];
      j++;
      cnt++;
    }
  }
}

void merge_sort(int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    merge_sort(left,mid);
    merge_sort(mid,right);
    merge(left,mid,right);
  }
}


int main(){
  int n,i,value;
  char tmp[5];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%s%d",tmp,&value);
    MERGE[i].mark = QUICK[i].mark = tmp[0];
    MERGE[i].value = QUICK[i].value = value;
  }
  quick_sort(0,n-1);
  merge_sort(0,n);
  for(i = 0; i < n;i++){
    if(QUICK[i].mark != MERGE[i].mark) {
      printf("Not stable\n");
      break;
    }
  }
  if(i == n) printf("Stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n",QUICK[i].mark,QUICK[i].value);
  }
  return 0;
}
  
  
  

