#include <stdio.h>

void print_int_array(int *data, int cnt){
	int i;

	for(i=0; i<cnt; i++){
		if( i < cnt-1 ){
			printf("%d ",data[i]);
		} else {
			printf("%d\n",data[i]);
		}
	}
}

int main(int argc, char** argv){
	int n,a[100];
	int i,j;
	int v;

	// Input
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}

	// Output
	print_int_array(a,n);

	// Sort
	for(i=1;i<n;i++){
		v = a[i];

		j = i-1;
		while(j>=0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;

		// Output
		print_int_array(a,n);
	}

	return 0;
}
