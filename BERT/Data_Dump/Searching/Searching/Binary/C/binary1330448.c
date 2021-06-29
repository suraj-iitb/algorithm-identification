#include <stdio.h>

int binarySearch(int);
int s[100000],n;

main(){
  int t[100000];
  int i,j,c=0,q;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    c+=binarySearch(t[i]);
  }

  printf("%d\n",c);
  return 0;
}

int binarySearch(int key){
  int left,right,mid;

  left=0;
  right=n;
  while(left < right){
    mid=(left + right)/2;
  if(s[mid]==key) return 1;
  else if( key < s[mid]) right=mid;
  else left = mid + 1;  
  }
  return 0;
}
  
