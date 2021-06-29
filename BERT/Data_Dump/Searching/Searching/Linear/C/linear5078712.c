
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 10000
#define QMAX 500
#define SMIN 0
#define SMAX pow(10,9)
#define TMIN 0
#define TMAX pow(10,9)
#define TRUE 1
#define FALSE 0

int linearSearch(int, int *, int);

int main() {
  int n, q;
  int s[NMAX], t[QMAX];
  int cnt=0; // number of same elements
  int i, j; // counter
  
  scanf("%d", &n);
  if(NMAX<n) {
    fprintf(stderr,"n <= %d\n", NMAX);
    exit(8);
  }
  for(i=0; i<n; i++) {
    scanf("%d", &s[i]);
    if(s[i]<SMIN || SMAX<s[i]) {
      fprintf(stderr,"%d <= an element in S <= %f\n", SMIN, SMAX);
      exit(8);
    }
  }
  scanf("%d", &q);
  if(QMAX<q) {
    fprintf(stderr,"q <= %d\n", QMAX);
    exit(8);
  }
  for(i=0; i<q; i++) {
    scanf("%d", &t[i]);
    if(t[i]<TMIN || TMAX<t[i]) {
      fprintf(stderr,"%d <= an element in T <= %f\n", TMIN, TMAX);
      exit(8);
    }
    for(j=0; j<i; j++)
      if(t[i]==t[j]) {
	fprintf(stderr,"the elements of T are different from each other\n");
	exit(8);
      }
  }
  
  for(i=0; i<q; i++)
    if(linearSearch(n, s, t[i]))
      cnt++;
  
  printf("%d\n", cnt);
  
  return 0;
}

int linearSearch(int n, int *s, int t) {
  int i; // counter
  
  for(i=0; i<n; i++)
    if(s[i]==t)
      return TRUE;

  return FALSE;
}

