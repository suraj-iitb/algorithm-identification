#include <stdio.h>
int s[100000],n;
int search(int);
int main(){
  int i,key,q,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    if(search(key)) cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}

int search(int key){
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;

    if(s[mid]==key) return 1;
    else if(s[mid]>key) right=mid;
    else left=mid+1;
  }
  return 0;
}
