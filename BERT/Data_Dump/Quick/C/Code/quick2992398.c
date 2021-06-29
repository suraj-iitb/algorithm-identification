#include<stdio.h>

#define Max 100000
#define S 1000000000

typedef struct Card{
  char suit;
  int value;
}Card;

Card L[Max / 2 + 2], R[Max / 2 + 2];

void merge(Card a[], int n, int l, int m, int r){
  int i, j, k, n1, n2;
  n1 = m - l;
  n2 = r - m;
  
  for(i = 0 ; i < n1 ; i++) L[i] = a[l + i];
  for(i = 0 ; i < n2 ; i++) R[i] = a[m + i];
  
  L[n1].value = R[n2].value = S;
  i = j = 0;
  
  for(k = l ; k < r ; k++){
    if(L[i].value <= R[j].value){
      a[k] = L[i++];
    }
    else{
      a[k] = R[j++];
    }
  }
}

void mergeSort(Card a[], int n, int l, int r){
  int m;
  if(l + 1 < r){
    m = (l + r) / 2;
    mergeSort(a, n, l, m);
    mergeSort(a, n, m, r);
    merge(a, n, l, m, r);
  }
}

int partition(Card a[], int n, int p, int r){
  int i, j;
  Card t, x;
  x = a[r];
  i = p - 1;

  for(j = p ; j < r ; j++){
    if(a[j].value <= x.value){
      i++;
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }

  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;

  return i + 1;
}

void quickSort(Card a[], int n, int p, int r){
  int q;
  if(p < r){
    q = partition(a, n, p, r);
    quickSort(a, n, p, q - 1);
    quickSort(a, n, q + 1, r);
  }
}


int main(){
  int n, i, v, stable = 1;
  Card a[Max], b[Max];
  char s[10];

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    scanf("%s %d", s, &v);
    a[i].suit = b[i].suit = s[0];
    a[i].value = b[i].value = v;
  }

  mergeSort(a, n, 0, n);
  quickSort(b, n, 0, n - 1);
  
  for(i = 0 ; i < n ; i++){
    if(a[i].suit != b[i].suit) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n", b[i].suit, b[i].value);
  }

  return 0;
}
