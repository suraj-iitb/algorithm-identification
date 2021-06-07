/*
ALDS1_4-A
??¶?´?
    n \leq 10,000
    q \leq 500
    0 \leq S???????´? \leq 10^9
    0 \leq T???????´? \leq 10^9
    T ???????´???????????????°??????
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1000000
#define S_MAXSIZE 100000
#define Q_MAXSIZE 500

int sys_err(char *str);

int main(void)
{
  FILE *fh;
  int i;
  int j;
  int s[S_MAXSIZE];
  int t[Q_MAXSIZE];
  int n;
  int q;
  int ans = 0;
  int x;

  /*  if ((fh = fopen("/home/muz/Downloads/ALDS1_4_A_in8.txt", "r")) == NULL) {
    sys_err("fopen");
  }
  */
  fh = stdin;

  fscanf(fh, "%d", &n);
  for (i=0; i<n; i++){
    fscanf(fh, "%d", &x);
    s[i] = x;
  }

  fscanf(fh, "%d", &q);
  for (i=0; i<q; i++){
    fscanf(fh, "%d", &x);
    t[i] = x;
  }

  for (i=0; i<q; i++){
    for (j=0; j<n; j++){
      if (s[j] == t[i]){
	ans+=1;
	break;
      }
    }
  }

  printf("%d\n", ans);

  exit(0);
}

int sys_err(char *str)
{
  fputs(str, stderr);
  exit(0);

  return(0);
}
