#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

//void Aoj_learning1();
//void Aoj_learning2();
//void Aoj_learning3();
//void Aoj_learning4();
void Aoj_learning5();

int main()
{
	Aoj_learning5();
}

void Aoj_learning5()
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

	// バブルソート
	int flag = 1;			
	int number1, number2;	// 比較元,比較対象
	int changeCount = 0;	// 交換回数
	for(int i = 0; i < intInputNum; i++)
	{
		for (int count = intInputNum-1; count > 0; count--)
		{
			ss = std::istringstream(sInputNum[count]);
			ss >> number1;
			ss = std::istringstream(sInputNum[count-1]);
			ss >> number2;
			if (number1 < number2)
			{
				sInputNum[count - 1] = std::to_string(number1);
				sInputNum[count] = std::to_string(number2);
				changeCount++;
			}
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
