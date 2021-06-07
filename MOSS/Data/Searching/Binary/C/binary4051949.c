#include<stdio.h>
#define N 100000

int main(){
  int n1,n2,i,j,c=0,left=0,right,mid;
  int in[N],serch[N];

  scanf("%d",&n1);

  for(i=0;i<n1;i++){
    scanf("%d",&in[i]);
  }

  scanf("%d",&n2);
  
  for(i=0;i<n2;i++){
    scanf("%d",&serch[i]);
  }

  right=n1;


  right=n1;
  for(i=0;i<n2;i++){
    left=0;
    right=n1;
   while(left<right){
    mid=(left+right)/2;
    if(in[mid]==serch[i]){
      c++;
      break;
    }
    else if (serch[i] < in[mid])right=mid;
    else left=mid+1;
  }
  }
  

  printf("%d\n",c);
  return 0;
}

