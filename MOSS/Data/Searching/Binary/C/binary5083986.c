#include<stdio.h>
#define N 100000
#define M 50000
#define MAX 1000000000

int binarySearch(int , int *, int );
int main(){
  int a,b[N],c,d[M],n,i,j,count = 0;
  scanf("%d",&a);
  for(i = 0; i < a; i++)
    scanf("%d",&b[i]);

  scanf("%d",&c);
  for(i = 0; i < c; i++)
    scanf("%d",&d[i]);

  for(i = 0; i < c; i++){
    n = d[i];
    j = i - 1;

    while(j >= 0 && d[j] > n){
      d[j+1] = d[j];
      j--;
    }
    d[j+1] = n;
  }


  for(i = 0; i < a; i++){
    if(b[i + 1] == b[i]) continue;
    n = binarySearch(c,d,b[i]);
    if(n == 0) count++;
  }

  printf("%d\n",count);
  return 0;
}

int binarySearch(int c, int *d, int key){
  int left = 0, right = c,mid;

  while(left < right){
    mid = (left + right) / 2;
    if (key == d[mid])
      return 0;

    else if(key > d[mid])
      left =  mid + 1;

    else
      right = mid;
  }

  return -1;
}
