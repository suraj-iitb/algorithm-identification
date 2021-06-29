#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int n;
int a[100];

void print(int a[], int n) {
  rep(i,n) {
    if(i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void insertionSort(int a[], int n) {
  for(int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;

    print(a, n);
  }

}

int main () {
  scanf("%d", &n);
  rep(i,n) scanf("%d", &a[i]);

  print(a, n);
  insertionSort(a, n);

  return 0;
}
