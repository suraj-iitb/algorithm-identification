#include<stdio.h>

int main(){
int n,q;
int i,j,count=0;
int left,right,mid;

scanf("%d",&n);
int S[n];
for(i=0;i<n;i++){
  scanf("%d",&S[i]);
}
scanf("%d",&q);
int T[q];
for(i=0;i<q;i++){
  scanf("%d",&T[i]);
}
for(i=0;i<q;i++){
  left = 0;
  right = n;
  while(left<right){
    mid=(left+right)/2;
    if(T[i]==S[mid]){
      count++;
      break;
    }
    else if(T[i]>S[mid]){
      left = mid+1;
    }
    else if(T[i]<S[mid]){
      right=mid;
    }
  }
}
printf("%d\n",count);

  return 0;
}

