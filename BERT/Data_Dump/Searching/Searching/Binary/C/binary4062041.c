#include<stdio.h>
#define N 100000
#define M 50000

int binarySearch(int *, int, int);

int main(){
  int S[N],n1,n2,T[M],key,count=0,c;
  int i,j,k;
  int left, right, mid;
  
  scanf("%d",&n1);
  for(i = 0; i < n1; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&n2);
  for(i = 0; i < n2; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<n2; i++){
    key = T[i];
    c = binarySearch(S,key,n1);
    if( c != -1 ) count++;
  }
       
  printf("%d\n",count);

  return 0;
}

int binarySearch(int S[], int key, int n){
  int left, right, mid;

  left = 0;
  right = n;

  while( left < right ){
    mid = ( left + right ) / 2;
    if(S[mid] == key) return mid;
    else if (key < S[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}
