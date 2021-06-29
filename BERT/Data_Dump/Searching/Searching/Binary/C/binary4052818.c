#include <stdio.h>

int main(){
  int i=0,j=0;
  int s,t;
  int count=0,key;
  int left=0,right=0,mid=0;
  scanf("%d",&s);
  int S[s];
  for(i=0;i<s;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&t);
  int T[t];
  for(i=0;i<t;i++){
    scanf("%d",&T[i]);
  }

    for(i=0;i<t;i++){
      key = T[i];
      left=0;
      right=s;
      while(left < right){
	mid = (left + right) / 2;
	if(S[mid] == key){
	  count++;
	  break;
	}
	else if(key < S[mid]){
	  right = mid;
	}
	else{
	  left = mid + 1;
	}
      }
    }

      printf("%d\n",count);
      return 0;
}


  
		 
  

