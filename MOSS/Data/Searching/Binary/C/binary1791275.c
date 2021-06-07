#include <stdio.h>




int main(){
  int i;
  int s,t;
  int count=0;
  int key,left,right,mid;

  scanf("%d",&s);
  int S[s];
  for(i=0;i<s;i++)scanf("%d",&S[i]);


  scanf("%d",&t);
  int T[t];
  for(i=0;i<t;i++)scanf("%d",&T[i]);


  for(i=0;i<t;i++){

    left=0;
    right=s;

    key=T[i];
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==key){
	//printf("%d",key);
	count++;
	break;
      }
      else if(key<S[mid])right=mid;
      else left = mid+1;
    }
  }

  printf("%d\n",count);
   return 0;
}
