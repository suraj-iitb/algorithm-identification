#include<stdio.h>

#define INFTY 2000000000
void margeSort(int, int);
void marge(int, int, int);

int a[500000], le[500000], ri[500000];
int cnt = 0;

int main(){
  int n, i;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  margeSort(0, n);

  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n", cnt);

  return 0;
}

void margeSort(int l, int r){
  int m;
  if(l+1 < r){
    m = (l + r)/2;
    margeSort(l, m);
    margeSort(m, r);
    marge(l, m, r);
  }
}

void marge(int l, int m, int r){
  int n1 = m - l;
  int n2 = r - m;
  int i, j, k;

  for(i = 0; i < n1; i++) le[i] = a[l + i];
  for(i = 0; i < n2; i++) ri[i] = a[m + i];

  le[n1] = ri[n2] = INFTY;
  i = j = 0;

  for(k = l; k < r; k++){
    cnt++;
    if(le[i] <= ri[j]){
      a[k] = le[i];
      i++;
    }else{
      a[k] = ri[j];
      j++;
    }
  }
}

