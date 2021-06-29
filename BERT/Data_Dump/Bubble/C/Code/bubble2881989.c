#include <stdio.h>
 
// 入力制約
#define NUM_MIN ( ( int ) 1 )
#define NUM_MAX ( ( int ) 100 )
#define ELEMENT_MIN ( ( int ) 0 )
#define ELEMENT_MAX ( ( int ) 100 )

// 制約判定結果
typedef enum
{
	kSuccess,
	kError
}Result;

// プロトタイプ宣言
Result checkNumRange( int num, int min, int max );
int execBubbleSort( int num, int* pArray );
void showArray( int num, int* pArray );
void swap( int* pX, int* pY );

//****************************************************/
// @brief  メイン関数
// @param  無し
// @return 正常終了なら0、異常終了なら-1を返す
//****************************************************/
int main( void )
{
	int i;
	int num;
	int array[NUM_MAX];
	int count;

	// 要素数の入力判定
	scanf( "%d\n", &num );
	if( checkNumRange( num, NUM_MIN, NUM_MAX ) == kError )
	{
		return -1;
	}

	// 要素の入力判定
	for( i = 0; i < num; i++ )
	{
		scanf( "%d", &array[i] );
		if( checkNumRange( array[i], ELEMENT_MIN, ELEMENT_MAX ) == kError )
		{
			return -1;
		}
	}

	// バブルソート実行
	count = execBubbleSort( num, &array[0] );
	// ソート回数を出力
	showArray( num, &array[0] );
	printf( "%d\n", count );

	return 0;
}

//****************************************************/
// @brief  入力値の制約判定
// @param  num : 判定対象の入力値
//         min : 最小値
//         max : 最大値
// @return 制約内ならkSuccess、制約外ならkErrorを返す
//****************************************************/
Result checkNumRange( int num, int min, int max )
{
	return ( ( num >= min ) && ( num <= max ) ) ? kSuccess : kError;
}

//****************************************************/
// @brief  バブルソートを実行し、ソート回数を返す
// @param  num    : 要素数
// @param  pArray : 要素を格納した配列先頭へのポインタ
// @return ソート回数
//****************************************************/
int execBubbleSort( int num, int* pArray )
{
	int i;
	int index = 0;	// 未ソート部分列の先頭インデックス
	int flag = 1;	// ソートしたら1, ソートしなければ0にする
	int count = 0;	// ソート回数

	while( flag )
	{
		flag = 0;
		for( i = num - 1; i >= index + 1; i-- )
		{
			if( pArray[i] < pArray[i - 1] )
			{
				// 要素入れ替え、ソート回数をカウント
				swap( &pArray[i], &pArray[i - 1] );
				flag = 1;
				count++;
			}
		}
		index++;
	}

	return count;
}
 
//****************************************************/
// @brief  変数の値を交換する
// @param  pX : 値を交換する変数1
// @param  pY : 値を交換する変数2
// @return 無し
//****************************************************/
void swap( int* pX, int* pY )
{
	int temp;

	temp = *pX;
	*pX = *pY;
	*pY = temp;
}

void showArray( int num, int* pArray )
{
	int i;

	for( i = 0; i < num; i++ )
	{
		if( i != num - 1 )
		{
			// 出力する要素の末尾以外はスペースを空ける
			printf( "%d ", pArray[i] );
		}
		else
		{
			// 出力する要素の末尾は改行を入れる
			printf( "%d\n", pArray[i] );
		}
	}
}

