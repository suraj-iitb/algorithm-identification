#include <stdio.h>
#define NUMBER 100

void print_array(int array[],int num){
	int i;
	
	for(i = 0; i < num - 1; i++)
		printf("%d ", array[i]);
	
	//スペースを出力したくないので最後の要素だけfor文外で出力
	printf("%d\n", array[i]);
}

int selectionSort(int array[],int num){
	int cnt = 0;
	int i, j , minj, temp;
	for(i = 0; i <= num - 1; i++){
		minj = i;
		for(j = i; j <= num - 1; j++){
			if(array[j] < array[minj])
				minj = j;
		}
		if(minj != i){
			temp = array[i];
			array[i] = array[minj];
			array[minj] = temp;
			cnt++;
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
	//選択ソート
	n = selectionSort(array, num);
	
	print_array(array, num);
	
	//交換回数を出力
	printf("%d\n", n);
	
	return 0;
}
