#include <stdio.h>
int main(){
  int i,j=0,c=0,n1,n2,retu1[100000],retu2[50000],left,right,mid;
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&retu1[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&retu2[i]);
  }

  for(i=0;i<n2;i++){
    left=0;
    right=n1;
    while(left<right){
      mid=(left+right)/2;
      if(retu1[mid]==retu2[i]){
	c++;
	break;
      }
      else if(retu1[mid]>retu2[i]){
	right=mid;
    }
      else
	left=mid+1;
  }
  }
  printf("%d\n",c);
  return 0;
}
