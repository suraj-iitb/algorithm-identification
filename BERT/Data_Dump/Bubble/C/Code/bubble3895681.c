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

	int flag = 1;
	while(flag){
		flag = 0;
		for(int i = n - 1; i > 0; i--){
			if(val[i] < val[i - 1]){
				flag = val[i - 1];
				val[i - 1] = val[i];
				val[i] = flag;
				flag = 1;
				changecount++;
			}
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
