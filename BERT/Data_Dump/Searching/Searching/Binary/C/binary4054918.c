#include<stdio.h>
#define MAX 100000

int Bis(int *,int,int);
int main() {

  int n,m,i;
  int num[MAX];
  int key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&num[i]);

  scanf("%d",&m);
  for(i=0;i<m;i++) {
    scanf("%d",&key);
    if( Bis(num,n,key) == 1 ) count++;
  }

  printf("%d\n",count);

  return 0;

}

int Bis(int *num,int n,int key) {

  int left=0;
  int right=n;
  int mid;
  
  while( left < right ) {
    
    mid = (left+right)/2;

    if(num[mid] == key) return 1;
    else if( key < num[mid]) right = mid;
    else left = mid+1;

  }

  return 0;

}
