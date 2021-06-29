#include <stdio.h>
int S[1000000],n;

int binary(int key){
  int left=0,mid;
  int right=n;
  while(left<right){
    mid=(left+right)/2;
    if(key==S[mid]){
      return 1;
    }
    else if(key>S[mid]){
     left=mid+1;
   }
    else {
   right=mid;
}
  }
  return 0;
}
int main()
{
int a,b,i,j,cnt,T[100000];

scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&S[i]);
}
scanf("%d",&b);
for(i=0;i<b;i++){
  scanf("%d",&T[i]);
  if(binary(T[i])){
   cnt++;
 }
}
printf("%d\n",cnt);
return 0;
}

