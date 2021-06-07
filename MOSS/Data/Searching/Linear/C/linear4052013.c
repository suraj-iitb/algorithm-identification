#include<stdio.h>
#define N 10000
#define Q 500
#define NOT_FOUND -1

int linearSearch(int *, int, int);

int main()
{
  int n,m,i,j,s[N],t[Q],ret,cnt = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&m);

  for(i = 0; i < m; i++){
    scanf("%d",&t[i]);
  }

  for(j = 0; j < m; j++){
    ret = linearSearch(s,n,t[j]);
    if(ret != NOT_FOUND){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  
  return 0;
}

int linearSearch(int A[], int n, int key)
{
  int i;

  i = 0;

  A[n] = key;
  while(A[i] != key){
    i++;
  }
  if(i == n)return NOT_FOUND;
  return i;
}

