#include<cstdio>
#include<algorithm>
using namespace std;

static const int MAX = 100;

void print_array(int n, int buf[]) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }

    printf("%d", buf[i]);
  }

  printf("\n");
}

int main() {
  int n = 0, buf[MAX];
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &buf[i]);

  print_array(n, buf);

  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && buf[j] < buf[j - 1]) {
      swap(buf[j], buf[j - 1]);
      j--;
    }

    print_array(n, buf);
  }

  return 0;
}

