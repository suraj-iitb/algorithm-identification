#include<stdio.h>
int main(){
  int n,q,ans=0;
  scanf("%d",&n);
  int i,S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
scanf("%d",&q);
int T[q];
for(i=0;i<q;i++){
  scanf("%d",&T[i]);
}
for(i=0;i<q;i++){
int left=0,right=n,mid;
while(left<right){
  mid=(left+right)/2;
  if(S[mid]==T[i]){ans++;
break;
  }
  else if(T[i]<S[mid])right=mid;
  else {left=mid+1;}
}
}
printf("%d\n",ans);
return 0;
}

