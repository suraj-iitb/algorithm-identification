#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;

int
main(int argc, char *argv[])
{
  int n, a[100];
  scanf("%d", &n);
  rep(i, n) scanf("%d", &a[i]);

  int cnt = 0, temp;

  for(int i = 0; i < n; i++){
    for(int j = n - 1; j > i; j--){
      if(a[j] < a[j - 1]){
	temp = a[j];
	a[j] = a[j - 1];
	a[j - 1] = temp;
	cnt++;
      }
    }
  }

  rep(i, n) {
    printf("%d", a[i]);
    if(i < n - 1) printf(" ");
  } endl;
  printf("%d", cnt); endl;

  return 0;
}

