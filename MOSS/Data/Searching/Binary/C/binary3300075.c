#include <stdio.h>
int main(){
  int n,q,S[100000],T[1000],i,j,count=0,a[10000],k,right,left,middle;
  scanf("%d",&n);
  for(i=0;i<n;i++)
	scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
	scanf("%d",&T[i]);
	right=n;
	left=0;
	middle=n/2;
	while(right!=left){
	  if(T[i]>S[middle]){//T４行目S２行目
		left=middle+1;
		middle=(left+right)/2;
		continue;
	  }else if(T[i]<S[middle]){
		right=middle;
		middle=(right+left)/2;
		continue;
	  }else{//T[i]=S[middle]
		count++;
		break;
	  }
	  
	}
  }
  printf("%d\n",count);
  return 0;
}

  


