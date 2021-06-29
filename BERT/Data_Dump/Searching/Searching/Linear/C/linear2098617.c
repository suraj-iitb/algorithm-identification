#include <stdio.h>

int main(){
	int i, j, n, s[10000], q, t[500], c=0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &t[i]);
	}
	
	for(j = 0; j < q; j++){
		i = 0;
		s[n] = t[j];
		while(s[i] != t[j]){
			i++;
		}
		if(i != n)
		c++;
	}
	
	printf("%d\n", c);
	
	return 0; 
}
