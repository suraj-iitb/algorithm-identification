#include <stdio.h>
#include <stdlib.h>

typedef unsigned char	U08;

#define ARRAY_SIZE_MIN	1
#define ARRAY_SIZE_MAX	100
#define INPUT_DATA_MIN	0
#define INPUT_DATA_MAX	100
#define OK				0
#define NG				1

static U08  SelectionSort_U08(U08 *u08p_input_data, U08 u08_data_num);
static void SwapNum_Void(U08 *u08p_x, U08 *u08p_y);


/***********************************************************************************
 ++module <main>
 ++outline
	メイン関数
 ++arguments
	<>	<u08_return_val>	[戻り値]
 ++supp
	<戻り値>
		OK：正常終了
		NG：異常終了
	<引数>
		なし
	<補足説明>
		なし
 ++end_module
************************************************************************************/
int main(void)
{
												/* 配列のデータ数 */
	U08 u08_data_num = (U08)0;					/* 変数定義 */
	U08 *u08p_input_data;						/* 入力したデータを格納するポインタ配列 */
	U08 u08_change_count = (U08)0;				/* 数値の入れ替えを行った回数 */
	U08 u08_i = (U08)0;							/* ループ変数 */
	U08 u08_return_val = (U08)OK;				/* 戻り値 */
	
	scanf("%d", &u08_data_num);					/* データ数入力 */
	
	if( (u08_data_num < (U08)ARRAY_SIZE_MIN) || ((U08)ARRAY_SIZE_MAX < u08_data_num) )	/* 入力値が範囲外だった場合 */
	{
		u08_return_val = (U08)NG;				/* 戻り値にNGを設定 */
	}
	else
	{
		u08p_input_data = (U08 *)calloc(u08_data_num + 1, sizeof(U08));		/* 動的にメモリ確保 */
		
		if(NULL == u08p_input_data)										/* メモリ確保に失敗した場合 */
		{
			u08_return_val = (U08)NG;									/* 戻り値にNGを設定 */
		}
		else
		{
			for(u08_i = (U08)0; u08_i < u08_data_num; u08_i++)			/* データ数に指定した回数だけループ */
			{
				scanf("%d", &u08p_input_data[u08_i]);					/* データ入力 */
				
				if( (u08p_input_data[u08_i] < (U08)INPUT_DATA_MIN)
					|| ((U08)INPUT_DATA_MAX < u08p_input_data[u08_i]) )	/* 入力値が範囲外だった場合 */
				{
					free(u08p_input_data);								/* メモリ解放 */
					u08_return_val = (U08)NG;							/* 戻り値にNGを設定 */
					break;
				}
				else
				{
					/* 何もしない */
				}
			}
			
			if(OK == u08_return_val)									/* 正しく数値入力が完了した(戻り値にOKが入っている)場合 */
			{
				u08_change_count = SelectionSort_U08(&u08p_input_data[0], u08_data_num);	/* 昇順ソート */
				
				for(u08_i = (U08)0; u08_i < u08_data_num; u08_i++)		/* 配列の末端までループ */
				{
					if(u08_i < u08_data_num - 1)						/* 表示するデータが、配列の最後のデータではない場合 */
					{
						printf("%d ", u08p_input_data[u08_i]);			/* 配列データと半角スペースを表示 */
					}
					else
					{
						printf("%d\n", u08p_input_data[u08_i]);			/* 配列データを表示して改行 */
					}
				}
				
				printf("%d\n", u08_change_count);						/* 数値を入れ替えた回数を表示 */
				free(u08p_input_data);									/* メモリ解放 */
			}
			else
			{
				/* 何もしない */
			}
			
		}
	}
	
	return u08_return_val;
}


/***********************************************************************************
 ++module <SelectionSort_U08>
 ++outline
	配列の数値を昇順に並び替える関数
 ++arguments
	<>	<>					[数値の入れ替え回数]
	<>	<u08p_input_data>	[数値が格納された配列]
	<>	<u08_data_num>		[データ数]
 ++supp
	<戻り値>
		数値の入れ替え回数
	<引数>
		u08p_input_data：数値が格納された配列
		u08_data_num   ：データ数
	<補足説明>
		なし
 ++end_module
************************************************************************************/
static U08  SelectionSort_U08(U08 *u08p_input_data, U08 u08_data_num)
{
															/* 数値の入れ替えを行った回数 */
	U08 u08_change_count = (U08)0;							/* 変数定義 */
	U08 u08_min_idx = (U08)0;								/* 最小値のインデックス */
	U08 u08_i = (U08)0;										/* ループ変数 */
	U08 u08_j = (U08)0;										/* ループ変数 */
	U08 u08_tmp;
	
	for(u08_i = (U08)0; u08_i < u08_data_num; u08_i++)		/* データ数だけループ */
	{
		u08_min_idx = u08_i;								/* 最小値のインデックスを更新 */
		
		for(u08_j = u08_i; u08_j < u08_data_num; u08_j++)	/* 配列の末端までループ */
		{
			if(INPUT_DATA_MIN == u08p_input_data[u08_j])	/* 最小入力値の場合 */
			{
				u08_min_idx = u08_j;						/* 最小値のインデックスを更新 */
				break;
			}
			else if( (0 != u08_i) && (u08p_input_data[u08_i - 1] == u08p_input_data[u08_j]) )	/* 1つ前の値と同じ場合 */
			{
				u08_min_idx = u08_j;						/* 最小値のインデックスを更新 */
				break;
			}
			else if(u08p_input_data[u08_j] < u08p_input_data[u08_min_idx])		/* 現在の最小値よりも小さい場合 */
			{
				u08_min_idx = u08_j;						/* 最小値のインデックスを更新 */
			}
			else
			{
				/* 何もしない */
			}
		}
		
		if(u08_min_idx != u08_i)							/* 最小値のインデックスが更新されている場合 */
		{
			SwapNum_Void(&u08p_input_data[u08_min_idx], &u08p_input_data[u08_i]);			/* 数値を入れ替え */
			u08_change_count++;								/* データ入れ替え回数をプラス1 */
		}
		else
		{
			/* 何もしない */
		}
	}
	
	return u08_change_count;
}

/***********************************************************************************
 ++module <SwapNum_Void>
 ++outline
	2つの変数の値を入れ替える関数
 ++arguments
	<>	<>			[]
	<>	<u08p_x>	[入れ替え対象変数1]
	<>	<u08p_y>	[入れ替え対象変数2]
 ++supp
	<戻り値>
		なし
	<引数>
		u08p_x：入れ替え対象変数1
		u08p_y：入れ替え対象変数2
	<補足説明>
		なし
 ++end_module
************************************************************************************/
static void SwapNum_Void(U08 *u08p_x, U08 *u08p_y)
{
										/* 一時保持変数 */
	U08 u08_tmp = 0;					/* 変数定義 */
	
	u08_tmp = *u08p_x;					/* u08p_xの値を保持 */
	*u08p_x = *u08p_y;					/* u08p_yの値をu08p_xに格納 */
	*u08p_y = u08_tmp;					/* 保持していたu08p_xの値をu08p_yに格納 */
}

