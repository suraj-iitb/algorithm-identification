#include <iostream>
#include <sstream>
#include <string>

int main()
{
	int input = 0;
	std::string sInput;
	std::istringstream ss;
	std::cin >> sInput;

	ss = std::istringstream(sInput);
	ss >> input;
	
	std::string s[100];
	int count = 0;
	while (count < input)
	{
		std::cin >> s[count];
		count++;
	}
	
	int v1;	// ソートする数値
	int v2;	// 比較対象

	// ソート前の数列を表示
	for (int k = 0; k < input; k++)
	{
		std::cout << s[k];
		if (k == input - 1)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << " ";
		}
	}

	// 数列をソートして表示する
	for (int i = 1; i < input; i++)
	{
		ss = std::istringstream(s[i]);
		ss >> v1;
		ss = std::istringstream(s[0]);
		ss >> v2;
		for (int j = 0; j < i; j++)
		{
			ss = std::istringstream(s[j]);
			ss >> v2;
			if (v2 > v1)
			{
				s[j] = std::to_string(v1);
				while (j < i)
				{
					ss = std::istringstream(s[j + 1]);
					s[j + 1] = std::to_string(v2);
					ss >> v2;
					j++;
				}
			}
		}
		for (int k = 0; k < input; k++)
		{
			std::cout << s[k];
			if (k == input - 1)
			{
				//if (i < input - 1)
				//{
					std::cout << std::endl;
				//}
			}
			else
			{
				std::cout << " ";
			}
		}
	}
}
