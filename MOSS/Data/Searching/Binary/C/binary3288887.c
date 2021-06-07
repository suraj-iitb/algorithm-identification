#include<stdio.h>
int a[100000];
int n;
int search(int key){
  int left=0,right=n,mid;
  while(1){
    if(left>=right) break;
    mid=(left+right)/2;
    if(key==a[mid])
      return 1;
    else if(key<a[mid])
	right=mid;
    else if(key>a[mid])
      left=mid+1;
    }
  return 0; 
}
int main(){
  int i,m,x;
  int sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&x);
    if(search(x)){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}

