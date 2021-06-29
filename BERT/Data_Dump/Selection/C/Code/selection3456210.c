#include <stdio.h>

//問題文より、入力されるデータの最大個数
#define MAXCOUNT 100

//ソートの結果と交換回数を出力する関数
void print(int array[], int size, int count);

int main(void)
{
	//i、jは繰り返し変数、countはループの回数を、tempは交換するデータを格納、min_indexは交換するデータの添字
	int i, j, count, temp, min_index;
	//sizeは配列の要素数を、arrayは入力される数値を格納
	int size;
	int array[MAXCOUNT];

	//データの個数を入力
	scanf("%d", &size);

	//データを入力
	for(i = 0; i < size; i++){
		scanf("%d", &array[i]);
	}

	count = 0;
	//配列の終端の一つ前まで走査
	for(i = 0; i < (size - 1); i++){
		min_index = i;
		//比較元の一つ後ろから比較開始
		for(j = (i + 1); j < size; j++){
			//小さい値から確定する
			if(array[j] < array[min_index]){
				min_index = j;
			}
		}
		//昇順に並び替える
		if(min_index != i){
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;

			//交換回数を加算
			count++;
		}
	}

	//結果を出力
	print(array, size, count);

	return 0;
}

void print(int array[], int size, int count)
{
	int i;

	//配列の中身を1行で表示し、最後に改行する
	for(i = 0; i < (size - 1); i++){
		printf("%d ", array[i]);
	}

	printf("%d\n", array[i]);
	//交換回数を表示
	printf("%d\n", count);
}
