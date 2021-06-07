#include<stdio.h>

int main(){
  int n,q,i,j,k;
  int left,right,mid,cnt;
  int s[100000],t[50000];

  cnt = 0;
  
   scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  for(j=0;j < q;j++){
    scanf("%d",&t[j]);
  }
    
  for(k=0;k < q;k++){
    left = 0; right = n;
    while( left < right){
      mid = (left + right) / 2;
      if (s[mid] == t[k]){
	cnt++;
	break;
      } else if (s[mid] > t[k]){
	right = mid;
      } else {
	left = mid + 1;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}


