#include <stdio.h>
int main(){
	int n,i,a[100],v,j,k,s,x;//n????????°


	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for (k = 0; k < n; k++){
		if(k>=1) printf(" ");
		printf("%d", a[k]);
	}
	printf("\n");
	for (s = 1; s< n; s++){
		v = a[s];
		j=s-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(x=0; x<n; x++){
			if(x>=1) printf(" ");
			printf("%d", a[x]);
		}
		printf("\n");

	}
}
