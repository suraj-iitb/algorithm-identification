#include <iostream>
#include <cstdlib>

#define STRSIZE 1024
#define MAXELNUM 100
#define STRELNUMSIZE 4

/**　関数のプロトタイプ宣言 */

void StrToIntArray( char*, int*);
void InsertionSort(int, int*);
void DisplayElements(int* , int);

/**
*Function Name : Main
*Action : 
*
*/

int main(void)
{
    int elemNum = 0;  /** Number of elements*/
    char strElNum[STRELNUMSIZE] = { "\0" }; /** 並べ替える数字の数　*/

    char strSpecLine[STRSIZE] = { "\0" }; /**　ソート対象数列(文字列)　*/
    int SpecLine[MAXELNUM] = { 0 };  /**　ソート対象数列　*/

    std::cin.getline(strElNum, STRELNUMSIZE); /**　ソート対象要素数入力受付　*/
    elemNum = std::atoi(strElNum);

    std::cin.getline(strSpecLine, STRSIZE); /**　ソート対象数列入力受付(文字列)　*/

    StrToIntArray( strSpecLine, SpecLine); 

    InsertionSort(elemNum, SpecLine);

    return 0;
}


/**
*関数:StrToIntArray
*機能:文字列を整数の配列へ変換する
*
*/


void StrToIntArray( char strSpecLine[], int SpecLine[])
{
    int i = 0, j = 0, ElementCount = 0;

    char strNum[5];

    for (i = 0; i < STRSIZE; i++) 
    {
        
        if (strSpecLine[i] == '\0') /**改行文字に当たった時*/
        {
            strNum[j] = '\0'; /**一時配列の最後に終端文字を挿入*/
            SpecLine[ElementCount] = std::atoi(strNum); /**(最後の数字を)整数に変換*/

            return; 
        }
        else if (strSpecLine[i] == ' ') /**空白(区切り文字)に当たった時*/
        {
            strNum[j] = '\0'; /**一時配列の最後に終端文字を挿入*/
            SpecLine[ElementCount] = std::atoi(strNum); /**文字列StrNumを整数に変換*/

            j = 0;
            ElementCount++;
        }
        else
        {
            strNum[j] = strSpecLine[i];
            j++;
        }
    }
    return;
}

/**関数名:InsertionSort
*機能:挿入ソートを実行し、挿入ソートの各ステップごとに表示する
*/

void InsertionSort(int elemNum, int SpecLine[])
{
    int j = 0;

    DisplayElements(SpecLine, elemNum);

    /**挿入ソート実行&表示*/

    for (int i = 1; i < elemNum; i++) 
    {

        /**Executing insertion sort*/
        int key = SpecLine[i]; /**Setting initial Key Value*/
        j = i - 1;
        
        while (( j >= 0) && (SpecLine[j] > key) ) /**When Array[j] is larger than key value*/
        {
            SpecLine[j + 1] = SpecLine[j];  /**Array[j] -> Array[j+1]*/
            j--;
        }

        SpecLine[j+1] = key; /**Key値は整列済みの最後尾に入る*/

        /**挿入ソートの各ステップ表示*/
        DisplayElements(SpecLine, elemNum);
    }
    return;
}

void DisplayElements(int* SpecimenArray, int ElemNum)
{
    for (int i = 0; i < ElemNum; i++)
    {
        std::cout << SpecimenArray[i]; /**要素一つを表示*/

        if (i == ElemNum - 1)
        {
            std::cout << std::endl; /**全要素を表示したら改行*/

        }
        else
        {
            std::cout << " "; /**次に表示する要素が残っている場合は空白を挿入*/
        }
    }
}

