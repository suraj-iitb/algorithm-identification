#include <stdio.h>
#define NUMBER 100

void print_array(int array[],int num){
	int i;
	
	for(i = 0; i < num - 1; i++)
		printf("%d ", array[i]);
	
	//スペースを出力したくないので最後の要素だけfor文外で出力
	printf("%d\n", array[i]);
}

int bubbleSort(int array[],int num){
	int cnt = 0;
	int j;
	int flag = 1;
	while(flag){
		flag = 0;
		for(j = num - 1; j >= 1; j--){
			if(array[j] < array[j-1]){
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
				flag = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void){
	int array[NUMBER];
	int num, i, n;
	
	scanf("%d", &num);
	
	for(i = 0; i < num; i++){
		//配列を入力
		scanf("%d", &array[i]);
	}
	//バブルソート
	n = bubbleSort(array, num);
	
	print_array(array, num);
	
	printf("%d\n", n);
	
	return 0;
}
