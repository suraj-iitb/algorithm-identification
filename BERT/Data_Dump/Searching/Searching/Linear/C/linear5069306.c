#include <stdio.h>

int main(){
  int i,j,k,n,m,cnt=0,a[10000+1],b[10000+1];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&m);

  for(i=0;i<m;i++){
    scanf("%d",&k);
      for(j=0;j<n;j++){
	if(k==a[j]){
	  cnt++;
	  break;
	}
      }
  }

  printf("%d\n",cnt);
  return 0;
}
      
    
    

