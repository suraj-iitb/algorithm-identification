#include <cstdio>

void bubbleSort(int a[], int n)
{
  int i, j;
  int cnt = 0;
  bool flag = true;
  for (i = 0; i < n || flag; i++) {
    flag = false;
    for (j = n - 1; j > i; j--) {
      if (a[j - 1] > a[j]) {
	int temp = a[j];
	a[j] = a[j - 1];
	a[j - 1] = temp;
	flag = true;
	cnt++;
      }
    }
  }
  for (i = 0; i < n - 1; i++) 
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
     
  printf("%d\n", cnt);
}

int main()
{
  int a[100];
  int n;
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) 
    scanf("%d", &a[i]);
  
  bubbleSort(a, n);

  return 0;
}

