#include <stdio.h>

int BinarySearch(int *,int,int);  

int main(){
  int s[100001],n,q,el,cnt=0,i;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&s[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&el);
    cnt+=BinarySearch(s,el,n);

  }

  printf("%d\n",cnt);

  return 0;
}

int BinarySearch(int *a,int el,int n){
  int right,left,mid;

  left=0;
  right=n;



  while(right>left){
    mid=(right+left)/2;
    
    if(a[mid]==el) return 1;

    if(el<a[mid]) right=mid;
    else left=mid+1;
  }

  return 0;
}

  

