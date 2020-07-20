#include<bits/stdc++.h>
using namespace std;

void trace(int a[], int N) {
  for (int i = 0; i < N; i++) {
    printf("%d", a[i]);
    if (i < N - 1) printf(" ");
  }
  printf("\n");
  return;
}

int bubblesort(int a[], int N) {
  int cnt = 0;
  bool flag = 1; //どこかが逆順であるか否か
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = 1;
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  int N; scanf("%d", &N);
  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  int cnt = bubblesort(a, N);
  trace(a, N);
  cout << cnt << endl;
  return 0;
}
