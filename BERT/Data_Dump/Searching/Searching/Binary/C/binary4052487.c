#include<stdio.h>

int main(){

  int i,a=0,j,l,c=0,n,num[100000],q,qnum[50000];
  int left, right, mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&qnum[j]);
  }
  
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left + right) /2;
      if(num[mid] == qnum[i]){
	c++;
	break;
      }
      else if(qnum[i] < num[mid]){
	right = mid;
      }
      else {
	left = mid +1;
      }
    }
  }
      
  printf("%d\n",c);
  return 0;
}

