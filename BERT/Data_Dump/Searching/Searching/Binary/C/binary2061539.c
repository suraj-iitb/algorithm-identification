#include <stdio.h>

int main(void)
{
  int n[100000], q[50000], n1, q1, i, j, k = 0, sta, left = 0;
  scanf("%d", &n1);
  for (i = 0; i < n1; i++)  {
    scanf("%d", &n[i]);
  }
  int right, mid;
  scanf("%d", &q1);
  for (i = 0; i < q1; i++)  {
    scanf("%d", &q[i]);
  }

  for (i = 0; i < q1; i++)  {
    right = n1;
    left = 0;
    while (left < right)  {
      mid = (left + right) / 2;
      if (n[mid] == q[i])  {
        k++;
        break;
      }
      else if (n[mid] > q[i])  {
        right = mid;
      }
      else  {
        left = mid + 1;
      }
    }
  }

  printf("%d\n", k);

  return 0;
}
