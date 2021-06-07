#include <stdio.h>

int main()
{
  int i, n, q, t, cnt=0;
  int beg, end, ctr;
  char *p=NULL;
  size_t linecap = 0;
  getline(&p, &linecap, stdin);
  for (n=0; *p!='\n'; n=n*10+*(p++)-'0');
  int s[n];
  p = NULL;
  getline(&p, &linecap, stdin);
  for (s[0]=0,i=0; *p!='\n'; p++) {
    if (*p==' ') s[++i] = *(++p)-'0';
    else         s[i] = s[i] * 10 + *p - '0';
  }
  p = NULL;
  getline(&p, &linecap, stdin);
  for (q=0; *p!='\n'; q=q*10+*(p++)-'0');
  p = NULL;
  getline(&p, &linecap, stdin);
  for (i=0; i<q; i++) {
    for (t=0; *p>='0'; t=t*10+*(p++)-'0');
    p++;
    beg = 0;
    end = n-1;
    while (beg<=end) {
      ctr = (beg+end)/2;
      if (t==s[ctr]) {
	cnt++;
	break;
      } else if (t<s[ctr]) {
	end=ctr-1;
      } else { // t>s[ctr]
	beg=ctr+1;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}

