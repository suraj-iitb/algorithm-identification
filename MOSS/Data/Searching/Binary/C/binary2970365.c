#include<stdio.h>

int main(){

  int n,m,x;
  int i,j,cnt=0,flag;
  int left,mid,right;
  
  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);

  int T[m];

  for(i=0;i<m;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<m;i++){
    left = 0;
    right = n;

    while(left<right){
      mid = (left + right) / 2;
      
      if(T[i]==S[mid]){
	cnt++;
	break;
      }else if(T[i]>S[mid]){
	left = mid + 1;
      }else{
	right = mid;
      }
    }
  }

  printf("%d\n",cnt);
  
  return 0;
}

