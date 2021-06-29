#include <stdio.h>
#include <stdlib.h>

char buf[16];

void selectionsort(int *a, int n)
{
  int i, j, mini, t, nswap = 0;
  for (i=0; i<n; i++) {
    mini = i;
    for (j=i; j<n; j++)
      if (a[j]<a[mini]) mini=j;
    if (i!=mini) {
      t = a[i];
      a[i] = a[mini];
      a[mini] = t;
      nswap++;
    }
  }
  buf[15]=0;
  buf[14] = ' ';
  for (i=0; i<n-1; i++) {
    if (a[i]==0)  putc_unlocked('0', stdout);
    for (j=13; a[i]>0; j--, a[i]/=10) buf[j]='0' + (a[i]%10);
    fputs(buf+j+1, stdout);
  }
  buf[14] = '\n';
  for (j=13; a[i]>0; j--, a[i]/=10) buf[j]='0' + (a[i]%10);
  fputs(buf+j+1, stdout);

  if (nswap==0)  putc_unlocked('0', stdout);
  for (j=13; nswap>0; j--, nswap/=10) buf[j]='0' + (nswap%10);
  fputs(buf+j+1, stdout);
}

int main()
{
  char *p = NULL;
  size_t linecap = 0;
  fgets(buf, 12, stdin);
  int n = atoi(buf);
  int *a = (int*)malloc(sizeof(int)*n);
  getline(&p, &linecap, stdin);
  a[0] = 0;
  int i=0;
  for (; *p!='\n'; p++) {
    if (*p == ' ') {
      a[++i] = *(++p)-'0';
    } else {
      a[i] = a[i] * 10 + *p - '0';
    }
  }
  selectionsort(a, n);

  return 0;
}

