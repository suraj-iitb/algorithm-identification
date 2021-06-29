#include<stdio.h>
#include<math.h>

int main(){
	int n;
	int val[100];
	int changecount = 0;

	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&val[i]);
	}

	for(int i = 0; i < n; i++){
		int min = i;
		for(int u = i; u < n; u++){
			if(val[u] < val[min]){
				min = u;
			}
		}
		if(min > i){
			int t = val[i];
			val[i] = val[min];
			val[min] = t;
			changecount++;
		}
	}
	
	printf("%d",val[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",val[i]);
	}
	printf("\n");
	printf("%d\n",changecount);
	return 0;
}
