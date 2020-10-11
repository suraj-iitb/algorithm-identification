#include <stdio.h>

void insertion();
void show();

int main(void){
	int size, i;
	scanf("%d",&size);
	int a[size];

	for(i = 0; i < size; i++)
		scanf("%d",&a[i]);

	show(a, size);
	insertion(a, size);
	return 0;
}

void insertion(int x[], int len){
	int i, j, v;
	for(i = 1; i < len; i++){
		v = x[i];
		for(j = i - 1; j >= 0; j--){
			if(x[j] > v){
				x[j+1] = x[j];
			} else break;
		}
		x[j+1] = v;
		show(x, len);
	}
}

void show(int x[], int len){
	int i;
	printf("%d",x[0]);
	for(i = 1; i < len; i++){
		printf(" %d",x[i]);
	}
	printf("\n");
}
