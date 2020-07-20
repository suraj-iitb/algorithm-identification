#include <cstdio>

int main() {
  int a[120];
  int n;
  
  
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  int count=0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j=n-1; j>0; j--) {
      if (a[j] < a[j-1]) {
	int tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	count++;
	flag = 1;
      }
    }
  }

 
  for (int i=0; i<n-1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n", count);
}
