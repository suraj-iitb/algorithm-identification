#include<stdio.h>
int main(){
  int a,b,i,j,flag=0;
  int left,right,mid;
  int aa[100000];
  int bb[50000];
  int count=0,judge=0;
  scanf("%d",&a);
  right=a;
  for(i=0;i<a;i++){
    scanf("%d",&aa[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&bb[i]);
    left=0;
    right=a;
    while(left<right){
        mid=(left+right)/2;
        if(aa[mid]==bb[i]){
            judge=1;
            break;
        }
        else if(bb[i]<aa[mid]){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    if(judge!=0){
      count++;
      flag=1;
      judge=0;
    }
  }
  if(flag==0){
    printf("0\n");
  }
  else{
    printf("%d\n",count);
  }
  return 0;
}

