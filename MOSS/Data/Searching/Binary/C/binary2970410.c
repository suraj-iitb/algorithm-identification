#include<stdio.h>
#define NUM 100000


int main(){
  int left=0,right,mid,n1,n2,i,j,key,count=0;
  int a[NUM];

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);

  for(i=0;i<n2;i++){
    scanf("%d",&key);
    left=0;
    right=n1;
    while(left<right){
      mid=(left+right)/2;
      if(a[mid]==key){
	count++;
	break;
      }
      else if(key<a[mid]){
	right=mid;
      }
      else left=mid+1;
    }
  }

  printf("%d\n",count);



  
  return 0;
}

