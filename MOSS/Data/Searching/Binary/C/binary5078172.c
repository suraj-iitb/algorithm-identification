#include<stdio.h>

int binary(int *,int *,int,int);

int main(){
  int S[100000],T[100000];
  int c,i,n,m;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&m);
  for(i=0;i<m;i++)scanf("%d",&T[i]);

  c = binary(S,T,n,m);

  printf("%d\n",c);

  return 0;
}

int binary(int *S,int *T,int n,int m){
  int i,right,left,mid,c=0;

  for(i=0;i<m;i++){
    left = 0;
    right = n;
    
    while(left < right){
      mid = (right + left)/2;
      if(S[mid] == T[i]){
	c++;
	break;
      }
      else if(T[i] < S[mid])right = mid;
      else left = mid + 1;
    }
  }
  return c;
}

