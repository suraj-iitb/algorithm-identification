#include <stdio.h>
#define N 100
int main(){
	int n,key,i,j,k;
	scanf("%d", &n);
	int array[n];
	for(i=0; i<n; i++){
		scanf("%d", &array[i]);
	}
	for(k=0; k<n; k++){
		if(k == n-1){printf("%d\n", array[k]);}
		else{printf("%d ", array[k]);}
	}
	for(i=1; i<n; i++){
		key = array[i];
		j = i-1;
		while((j>=0) && (array[j]> key)){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
		for(k=0; k<n; k++){
			if(k == n-1){printf("%d\n", array[k]);}
			else{printf("%d ", array[k]);}
		}
	}
	return 0;
}
