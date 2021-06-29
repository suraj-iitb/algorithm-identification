#include <stdio.h>

void show();
void bubble();
void select();

int count = 0;

int main(void){
	int size, i;
	scanf("%d",&size);
	int a[size];

	for(i = 0; i < size; i++)
		scanf("%d",&a[i]);

	select(a, size);
	show(a, size);
	printf("%d\n",count);
	return 0;
}

void select(int x[], int len){
	int i, j, minj, temp;
	for(i = 0; i < len; i++){
		minj = i;
		for(j = i; j < len; j++){
			if(x[j] < x[minj]){
				minj = j;
			}
		}
		if(i != minj){
			temp = x[minj];
			x[minj] = x[i];
			x[i] = temp;
			count++;
		}
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
