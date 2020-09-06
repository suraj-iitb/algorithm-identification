/*
 * a.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const int MAX_N = 100;

/* typedef */

/* global variables */

int as[MAX_N];

/* subroutines */

void print_seq(int n, int ds[]) {
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", ds[i]);
  }
  putchar('\n');
}

/* main */

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> as[i];
  print_seq(n, as);
  
  for (int i = 1; i < n; i++) {
    int key = as[i];
    int j = i - 1;
    while (j >= 0 and as[j] > key) {
      as[j + 1] = as[j];
      j--;
    }
    as[j + 1] = key;

    print_seq(n, as);
  }

  return 0;
}
