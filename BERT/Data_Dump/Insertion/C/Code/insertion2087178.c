#include <stdio.h>
int main(){
  int nums[101];
  int sorted[101];
  int n;
  int i=0;
  int v;
  int j;
  int k;
  scanf("%d\n",&n );
  while (i<n) {
    scanf("%d",&nums[i]);
    i++;
  }
  
  for (i = 0; i < n; i++) {
    
    v=nums[i];
  	j=i-1;
  	while(j>=0&&nums[j]>v){
  	  nums[j+1]=nums[j];
  	   j--;
  	}
  	nums[j+1]=v;
  		k=0;
  	
  	while(k<n){
  		printf("%d",nums[k]);
  		k++;
  		if(k!=n)
  		printf(" ");
  	}
  	  printf("\n");

  }
  	return 0;
	
}
