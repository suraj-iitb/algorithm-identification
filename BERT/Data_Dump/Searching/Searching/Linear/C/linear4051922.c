#include <stdio.h>

int linearSearch(int *, int, int);

int main(){
  int n, q, s[10000], t, a, count=0;
  
  scanf("%d",&n);
  for(a = 0; a < n; a++){
    scanf("%d",&s[a]);
  }
  scanf("%d",&q);
  for(a = 0; a < q; a++){
    scanf("%d",&t);
    if(linearSearch(s,n,t) != -1)count++;
  }

  printf("%d\n",count);

  return 0;

}

int linearSearch(int *p, int n, int key){
  int a=0;
  *(p+n) = key;
  while(*(p+a) != key){
    a++;
    if(a == n) return -1;
  }
  return a;
}

