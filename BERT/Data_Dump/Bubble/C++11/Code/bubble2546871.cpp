
#include <iostream>
#include <vector>

inline void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a[100], t = 0,count=0;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> a[i];
	}
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = t - 1; i != 0; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]); count++;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < t; i++)
	{
		if (i) std::cout << " ";
		std::cout << a[i];
	}
	std::cout << std::endl << count << std::endl;

}
