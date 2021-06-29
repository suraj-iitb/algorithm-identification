#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

//void Aoj_learning1();
//void Aoj_learning2();
//void Aoj_learning3();
//void Aoj_learning4();
//void Aoj_learning5();
void Aoj_learning6();

int main()
{
	Aoj_learning6();
}

void Aoj_learning6()
{
	std::string sInput;
	int intInputNum = 0;
	std::istringstream ss;	// 汎用文字列ストリーム

	// 入力個数の取得
	std::cin >> sInput;
	ss = std::istringstream(sInput);
	ss >> intInputNum;
	if (intInputNum > 100 || 1 > intInputNum)
	{
		exit(0);
	}

	// 数列を取得
	std::string sInputNum[100];
	for (int count = 0; count < intInputNum; count++)
	{
		std::cin >> sInputNum[count];
	}

	// 選択ソート
	int imin;				// 最小値格納先
	int changeNum;			// 交換元の配列番号
	int changeCount = 0;	// 交換回数
	int flag;				// 交換発生フラグ
	int temp;
	std::string sTemp;
	for (int count = 0; count < intInputNum; count++)
	{
		// フラグ初期化
		flag = 0;

		// 未整理領域から最小値を探す
		ss = std::istringstream(sInputNum[count]);
		ss >> imin;
		for (int i = count; i < intInputNum; i++)
		{
			ss = std::istringstream(sInputNum[i]);
			ss >> temp;
			if (imin > temp)
			{
				imin = temp;
				changeNum = i;
				// 交換が発生する場合フラグを立てる
				flag = 1;
			}
		}

		// 交換する必要がある場合交換と同時に回数をカウント
		if (flag == 1)
		{
			sTemp = sInputNum[count];
			sInputNum[count] = sInputNum[changeNum];
			sInputNum[changeNum] = sTemp;
			changeCount++;
		}
	}

	// 整列した数列を表示
	for (int k = 0; k < intInputNum; k++)
	{
		std::cout << sInputNum[k];
		if (k == intInputNum - 1)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << " ";
		}
	}
	// 交換回数を表示
	std::cout << changeCount << std::endl;
}
