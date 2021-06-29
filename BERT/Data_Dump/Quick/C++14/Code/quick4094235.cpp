#include<iostream>
#include<cstdio>
using namespace std;
typedef struct{
  char sign;
  int num;
}card;
int n;
card l[50005], r[50005];
int partition(card qarr[], int p, int t) {
  int x = qarr[t].num, change = p;
  card tmp;
  for (int i = p; i<t; ++i) {
    if (qarr[i].num <= x) {
      tmp = qarr[i];
      qarr[i] = qarr[change];
      qarr[change] = tmp;
      ++change;
    }
  }
  tmp=qarr[t];
  qarr[t]=qarr[change];
  qarr[change]=tmp;
  return change;
}
void quicksort(card qarr[], int p, int t) {
  if (p<t) {
    int q = partition(qarr, p, t);
    quicksort(qarr, p, q - 1);
    quicksort(qarr, q + 1, t);
  }
}
void merge(card marr[], int left, int mid, int right) {
  int x = mid - left, y = right - mid;
  for (int i = 0; i<x; ++i) l[i] = marr[left + i];
  for (int i = 0; i<y; ++i) r[i] = marr[mid + i];
  l[x].num = r[y].num = 1000000001;
  x = y = 0;
  for (int i = left; i<right; ++i) {
    if (l[x].num <= r[y].num) marr[i] = l[x++];
    else marr[i] = r[y++];
  }
}
void mergesort(card marr[], int left, int right) {
  if (left + 1<right) {
    int mid = (right + left) / 2;
    mergesort(marr, left, mid);
    mergesort(marr, mid, right);
    merge(marr, left, mid, right);
  }
}
int main() {
  card marr[100000], qarr[100000];
  scanf("%d", &n);
  for (int i = 0; i<n; ++i) {
    scanf("\n%c %d", &qarr[i].sign, &qarr[i].num);
    marr[i] = qarr[i];
  }
  quicksort(qarr, 0, n - 1);
  mergesort(marr, 0, n);
  int flag = 1;
  for (int i = 0; i<n; ++i)
    if (marr[i].sign != qarr[i].sign) flag = 0;
  if (flag) printf("Stable\n");
  else printf("Not stable\n");
  for (int i = 0; i<n; ++i) printf("%c %d\n", qarr[i].sign, qarr[i].num);
  return 0;
}
