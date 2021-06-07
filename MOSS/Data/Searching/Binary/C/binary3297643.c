#include<stdio.h>

int main(){
  int i, j, S[100000], T[50000], n, q, left, right, mid, cnt=0, flag=0;
  scanf("%d", &n);
  if(n > 0 && n <= 100000){
    for(i = 0; i < n; i++){
      scanf("%d", &S[i]);
      if(i > 0){
	if(S[i-1] > S[i] || S[i] > 1000000000) flag = 1;
      }
    }

    if(flag != 1){
      scanf("%d", &q);
      if(q > 0 && q <= 50000){
	for(i = 0; i < q; i++){
	  scanf("%d", &T[i]);
	  if(T[i] > 1000000000) flag = 1;
	}
	if(flag != 1){
	  for(j = 0; j < q; j++){
	    left = 0;
	    right = n;
	    while(left < right){
	      mid = (left + right) / 2;
	      if(S[mid] == T[j]){
		cnt++;
		break;
	      }else if(T[j] < S[mid]){
		right = mid;
	      }else{
		left = mid + 1;
	      }
	    }
	  }
      
	  printf("%d\n", cnt);
	}
      }
    }
  }
  return 0;
}

