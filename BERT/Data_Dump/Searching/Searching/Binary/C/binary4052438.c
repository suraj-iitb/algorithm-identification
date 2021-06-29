#include <stdio.h>

int s[100000],n,ans=0;

void binarySearch(int a){
  int j=0,l=0,r=n,mid;
  while(l<r){
    mid = (l+r)/2;
    if(s[mid]==a){
      ans++;
      break;
    }
    else if(a<s[mid])r=mid;
    else l = mid + 1;
  }
}

int main(){
  int q,i,pass;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&pass);
    binarySearch(pass);
  }
  printf("%d\n",ans);
  return 0;
}

