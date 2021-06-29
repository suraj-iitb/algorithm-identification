#include <stdio.h>

#define N 10000
#define Q 500

int s[N];
int n;

int linearSearch(int);

int main()
{

  int i, j, q, c = 0;
  int t[Q];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for(j=0; j<q; j++){
    scanf("%d", &t[j]);
  }

  for(j=0; j<q; j++){
    if(linearSearch(t[j]) == 1){
      c++;
    }
  }

  printf("%d\n", c);

  return 0;

}

int linearSearch(int key)
{

  int a = 0;
  s[n] = key;

  while(s[a] != key){
    a++;
  }
    if(a == n){
      return 0;
    }

    else return 1;
}
