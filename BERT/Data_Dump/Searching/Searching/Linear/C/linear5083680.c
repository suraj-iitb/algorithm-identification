#include <stdio.h>

#define MAX 10000

int linearSearch(int *, int, int);

int main(){

  int n, q, t, cnt = 0;
  int s[MAX], i;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &t);
    if(linearSearch(s, n, t) == 1) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}


int linearSearch(int *s, int n, int key){
int i = 0;
s[n] = key;
while(s[i] != key) i++;

if(i == n) return 0;
 else return 1;

}

