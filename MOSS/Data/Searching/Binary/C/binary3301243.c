#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int n,q,mid,s[N],t[Q],i,j,key[N],left,right,judge=0,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]); 
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]); 

  for(i=0;i<q;i++){
    left = 0;
    right = n;
    key[count]=t[i];
      for(j=0;j<count;j++){
	if(key[j]==t[i]){
	  judge=1;
	  break;
	}
      }
      if(judge==1){
	judge=0;
	continue;
      }
      while(1){
	mid = (left + right) / 2;
	if (s[mid] == key[count]){
	  count++;
	  break;
	}else if(key[count]<s[mid]) right = mid;
	else left = mid + 1;
      if(left>=right) break;
      }
  }

  

  printf("%d\n",count);

  return 0;
}

