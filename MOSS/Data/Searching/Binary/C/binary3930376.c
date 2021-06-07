#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>



int main() {
	int n;
	scanf("%d",&n);
	
	int S_value[n]; //今更ながら要素数はnでもいいのでは？

	for(int i = 0; i < n; i++){
		scanf("%d",&S_value[i]);
	}
	
	int q;
	scanf("%d",&q);
	int counter = 0;
	
	for(int i = 0; i < q; i++){
		int val;
		scanf("%d",&val);
		
		int left = 0;
		int right = n;
		int mid;
		for(;left < right;){
			mid = (left + right) / 2;
			if(S_value[mid] > val){
				right = mid;
			}else if(S_value[mid] < val){
				left = mid + 1;
			}else{
				counter++;
				break;
			}
		}
	}
	
	
	printf("%d\n",counter);
	return 0;
}




