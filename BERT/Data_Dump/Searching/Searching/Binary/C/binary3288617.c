#include<stdio.h>
int serch(int S[],int key,int n){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (right + left) / 2;
    if( S[mid] == key)
	return 1;
    else if( key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }

  return 0;
}



int main(){
  int n,i,S[100000],q,key,sum=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);
  
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    if(serch(S,key,n))
      sum++;
  }

  printf("%d\n", sum);
  return 0;
}

