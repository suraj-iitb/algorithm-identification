#include <stdio.h>

void insertion();
void show();
void bubble();

int count = 0;

int main(void){
	int size, i;
	scanf("%d",&size);
	int a[size];

	for(i = 0; i < size; i++)
		scanf("%d",&a[i]);

	//insertion(a, size);
	bubble(a, size);
	show(a, size);
	printf("%d\n",count);
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

void bubble(int x[], int len){
	int flag = 1, j, temp;
	while(flag){
		flag = 0;
		for(j = len-1; j > 0; j--){
			if(x[j] < x[j-1]){
				temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
				flag = 1;
				count++;
			}
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
