#include <stdio.h>

int main(void) {
	
	
	int i,j;
	int flag;
	int n;
	int q;
	int array_n[10000];
	int array_q[500];
	int count =0;
	
	scanf("%d",&n);
	for(i =0;i<n;i++){
		scanf("%d",&array_n[i]);
	}
	for(i=0;i<n-1;i++){
		for(j =i+1;j<n;j++){
			if((array_n[j] != -1) && (array_n[i] == array_n[j])){
				array_n[i] = -1;
			}
		}
	}
	scanf("%d",&q);
	for(i =0;i<q;i++){
		scanf("%d",&array_q[i]);
	}
	
	for(i = 0;i<n;i++){
		for(j =0;j<q;j++){
			if(array_n[i]==array_q[j]){
				count++;
				break;
			}
		}
	}

	printf("%d\n",count);
	
	return 0;
}

