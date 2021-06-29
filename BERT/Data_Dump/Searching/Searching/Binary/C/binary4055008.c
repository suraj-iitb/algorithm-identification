#include<stdio.h>

int main(){
  int a[1000000],n,i,q,key,sum = 0,right,left,mid;

  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  
  scanf("%d",&q);

  for(i = 0;i < q;i++){
    scanf("%d",&key);

    left = 0;
    right = n;
    while(left < right){
      mid = (right + left) / 2;
      if(key == a[mid]){
	sum++;
	break;
      }
      else if(key > a[mid]){
	left = mid + 1;
      }
      else{
	right = mid;
      }
    }
  }
  
  printf("%d\n",sum);
  
  return 0;
}

