#include<stdio.h>

void intAryScan(int b[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    scanf("%d", &b[i]);
  }
  return;
}

int main()
{
  int s[10000], t[500], n, q;
  int c, i, j;

  scanf("%d", &n);
  intAryScan(s, n);
  scanf("%d", &q);
  intAryScan(t, q);

  c = 0;
  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(t[i] == s[j]){
        c++;
		break;
      }
    }
  }
  printf("%d\n", c);

  return(0);
}
