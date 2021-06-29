#include <stdio.h>
int main()
{
   int i, j, n, S[100000], q, T[50000], key;
   int left, right, mid;
   int count = 0;
     
    scanf("%d",&n);
     
    for(i = 0; i < n; i++){
        scanf(" %d",&S[i]);
    }
    scanf("%d",&q);
     
    for(i = 0; i < q; i++){
        scanf(" %d",&T[i]);
    }
    
	for(key = 0; key < q; key++){
		left = 0;
		right = n;
		while (left < right){
			mid = (left + right) / 2;
			if (S[mid] == T[key]){ 
			count++;
			break;
			}else if(T[key] < S[mid]){
			right = mid;
			}else{
			left = mid + 1;
			}
		}
	}

	printf("%d\n",count);
	
	return 0;
}
