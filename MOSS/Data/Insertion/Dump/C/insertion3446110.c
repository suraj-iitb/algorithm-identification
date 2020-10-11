#include <stdio.h>

//問題文より、入力されるデータの最大個数
#define MAXCOUNT 100

//ソートの途中結果を表示する関数
void print(int array[], int size);

int main(void)
{
	//i、jは繰り返し変数、tempは挿入するデータを格納
	int i, j, temp;
	//sizeは配列の要素数を、arrayは入力される数値を格納
	int size;
	int array[MAXCOUNT];

	//データの個数を入力
	scanf("%d", &size);

	//データを入力
	for(i = 0; i < size; i++){
		scanf("%d", &array[i]);
	}

	//配列の先頭の一つ後ろから開始
	for(i = 1; i < size; i++){
		//途中経過を表示
		print(array, size);

		//コピーを取る
		temp = array[i];
		//適切挿入位置まで整列済みのデータを後方にずらす
		for(j = i; (j > 0) && (temp < array[j - 1]); j--){
			array[j] = array[j - 1];
		}
		//データを挿入する
		array[j] = temp;
	}

	//最終結果を表示
	print(array, size);

	return 0;
}

void print(int array[], int size)
{
	int i;

	//配列の中身を1行で表示し、最後に改行する
	for(i = 0; i < (size - 1); i++){
		printf("%d ", array[i]);
	}

	printf("%d\n", array[i]);
}
