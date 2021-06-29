#include <stdio.h>

int main(){
    int S[100000];
    int T[50000];
    int n, q, i, count = 0;
    int low, high, mid;

    //input
    scanf("%d",&n);
    for(i = 0; i < n; i++){
      scanf("%d",&S[i]);
    }

    scanf("%d",&q);
    for(i = 0; i < q; i++){
      scanf("%d",&T[i]);
    }
    
    //excution
    for(i = 0; i < q; i++){
      
      low = 0;
      high = n-1;
      
      while(low <= high){
	
	mid = (low + high) / 2;
	if (S[mid] == T[i]) {
	  count++;
	  break;
	}
	else if (S[mid] < T[i]){
	  low = ++mid;
	}
	else high = --mid;
    
      }
      
    }
    
    //output
    printf("%d\n",count);

    return 0;
}
