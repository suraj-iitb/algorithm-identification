#include <stdio.h>

int linearSearch(int, int[]);
int n;

int main()
{
  int a,i,data[10000],q,key,cnt=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&data[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    a = linearSearch(key,data);
    if(a != n) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int linearSearch(int key, int a[]){
  int i=0;
  while((i<n) && (key != a[i])) i++;
  return i;
}
