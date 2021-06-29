#include<stdio.h>

int main(){
	int size;
	int val[100];
	scanf("%d",&size);
	
	for(int i = 0; i < size; i++){
		scanf("%d",&val[i]);
	}
	
	//sort
	for(int i = 0; i < size; i++){
		int v = val[i];
		for(int u = i - 1; u >= 0 && val[u] > v; u--){
			val[u + 1] = val[u];
			val[u] = v;
		}
		
		//output
		for(int o = 0; o < size - 1; o++){
			printf("%d ",val[o]);
		}
		printf("%d\n",val[size - 1]);
	}
	return 0;
}
