#include <stdio.h>
#define SMAX 1000000

int S[SMAX];
int n;

int binaryserch(int bs)
{ 
    int left = 0; 
    int right = n; 
    int mid;

    while( left < right){
     mid = (left + right)/2;
     if( bs == S[mid] ) {
      return 1;
    }
     if( bs > S[mid] ) {
      left = mid + 1;
    }
     else if (bs < S[mid] ) {
      right = mid;
    }
   }
    return 0;
}

int main()
{ 
  int i=0,j=0,q,count=0,T;
  int c;

  scanf("%d",&n);
  while(i < n){
    scanf("%d",&S[i]);
    i++;
  }  
  scanf("%d",&q);
  while(j < q ){
    scanf("%d",&T);
    c = binaryserch(T);
    if(c == 1) count++;
    j++;
  }
    
    printf("%d\n",count);
    return 0;
}
