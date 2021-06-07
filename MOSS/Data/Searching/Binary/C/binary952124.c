#include <stdio.h>
#define Max 100000
#define max 50000
main(){

  int n[Max],q[max];
  int a,b,i,j,k,count=0,left,right,mid;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&n[i]);
  }

  scanf("%d",&b);
  for(j=0;j<b;j++){
    scanf("%d",&q[j]);
  }




  for(k=0;k<b;k++){
    left=0;
    right=a;
    while(left<right){
      mid = (left+right)/2;
      if(n[mid]==q[k]){
	count++;
	break;
      }
      else if(q[k]<n[mid])
	right=mid;
      else
	left = mid+1;
    }
  }
  printf("%d\n",count);
  return 0;
}
