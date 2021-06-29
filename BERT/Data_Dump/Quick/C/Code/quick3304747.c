#include<stdio.h>
#define INFINITY 1000000001
#define N 100000

typedef struct{
  int number;
  char mark;
}Card;

void merge(Card *, int, int, int);
void mergeSort(Card *, int, int);
int partition(Card *, int, int);
void quickSort(Card *, int , int);

int main(){
  Card out1[N], out2[N];
  int n, v, f = 1;
  int i;
  char c;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf(" %c %d", &c, &v);
    out1[i].mark = c;
    out2[i].mark = c;
    out1[i].number = v;
    out2[i].number = v;
  }

  /*for(i=0;i<n;i++){
    printf("%c %d\n", out1[i].mark, out1[i].number);
    }*/

  mergeSort(out1, 0, n);
  quickSort(out2, 0, n-1);

  for(i=0;i<n;i++){
    if(out1[i].mark != out2[i].mark) f = 0;
  }

  /*for(i=0;i<n;i++){
    printf("%c %d\n", out1[i].mark, out1[i].number);
    }*/
  
  if(f == 0) printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n", out2[i].mark, out2[i].number);
  }
  
  return 0;
}

void merge(Card *s, int left, int mid, int right){
  int n1, n2;
  int i, j, k;
  
  n1 = mid - left;
  n2 = right - mid;
  Card l[n1+1], r[n2+1];

  for(i=0;i<n1;i++){
    l[i] = s[left + i];
  }
  for(i=0;i<n2;i++){
    r[i] = s[mid + i];
  }
  l[n1].number = INFINITY;
  r[n2].number = INFINITY;

  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(l[i].number <= r[j].number){
      s[k] = l[i];
      i++;
    }
    else{
      s[k] = r[j];
      j++;
    }
  }
}

void mergeSort(Card *s, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}

int partition(Card *a, int p, int r){
  int x;
  int i, j;
  Card v;
  x = a[r].number;
  i = p - 1;
  for(j=p;j<r;j++){
    if(a[j].number <= x){
      i++;
      //a[i]とa[j]を交換
      v = a[i];
      a[i] = a[j];
      a[j] = v;
    }
  }
  //a[i+1]とa[r]を交換
  v = a[i+1];
  a[i+1] = a[r];
  a[r] = v;

  return i+1;
}

void quickSort(Card *a, int p, int r){
  int q;
  if(p < r){
    q = partition(a, p, r);
    quickSort(a, p, q-1);
    quickSort(a, q+1, r);
  }
}

