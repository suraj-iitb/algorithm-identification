#include<stdio.h>
#include<string.h>

#define SIZE 100001
#define INF 2000000000

typedef struct {
  char mark[2];
  int num;
} card;

card Quick[SIZE];
card Merge[SIZE];

int partition(int p, int r){
  int i, j, x;
  card temp;

  x = Quick[r].num;
  i = p-1;

  for(j = p; j <= r-1; j++){
    if(Quick[j].num <= x){
      i = i + 1;

      // 入れ替え
      strcpy(temp.mark,     Quick[i].mark);
      strcpy(Quick[i].mark, Quick[j].mark);
      strcpy(Quick[j].mark, temp.mark);
      
      temp.num     = Quick[i].num;
      Quick[i].num = Quick[j].num;
      Quick[j].num = temp.num;
    }
  }
  strcpy(temp.mark,       Quick[i+1].mark);
  strcpy(Quick[i+1].mark, Quick[r].mark);
  strcpy(Quick[r].mark,   temp.mark);

  temp.num       = Quick[i+1].num;
  Quick[i+1].num = Quick[r].num;
  Quick[r].num   = temp.num;

  return i+1;
}

void quicksort(int p, int r){
  int q;

  if(p < r){
    q = partition(p, r);
    quicksort(p, q-1);
    quicksort(q+1, r);
  }
}

void merge(int left, int mid, int right){ // left:0, mid:1, right:2
  int i, j, k;
  int n1, n2;
  card L[SIZE+1], R[SIZE+1];

  n1 = mid   - left; // 1 - 0 = 1
  n2 = right - mid;  // 2 - 1 = 1

  for(i = 0; i < n1; i++){
    strcpy(L[i].mark, Merge[left+i].mark);
    L[i].num = Merge[left+i].num;
  }
  for(i = 0; i < n2; i++){
    strcpy(R[i].mark, Merge[mid+i].mark);
    R[i].num = Merge[mid+i].num;
  }
  L[n1].num = INF; // L[n1] = {9, INF}
  R[n2].num = INF; // R[n2] = {6, INF}

  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i].num <= R[j].num){
      strcpy(Merge[k].mark, L[i].mark);
      Merge[k].num = L[i].num;
      i = i + 1;
    } else {
      strcpy(Merge[k].mark, R[j].mark);
      Merge[k].num  = R[j].num;
      j = j + 1;
    }
  }
}

void mergeSort(int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

void judge(int n){
  int i;
  for(i = 1; i <= n; i++){
    if(strcmp(Quick[i].mark, Merge[i-1].mark) != 0){
      printf("Not stable\n");
      break;
    }
  }
  if(i == n+1) printf("Stable\n");
}

void print(int n){
  int i;
  for(i = 1; i <= n; i++){
    printf("%s %d\n", Quick[i].mark, Quick[i].num);
  }
}

int main(){
  int i, n;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%s %d", Quick[i].mark, &Quick[i].num);
    strcpy(Merge[i-1].mark, Quick[i].mark);
    Merge[i-1].num = Quick[i].num;
  }
  quicksort(1, n);
  mergeSort(0, n);
  
  judge(n);
  print(n);

  return 0;
}
