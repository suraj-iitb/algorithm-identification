#include <iostream>
#include <vector>

void output(const std::vector<int>& array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		std::cout << array[i];
		if( i < array.size() - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	std::vector<int> array(n);
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];
	output(array);

	for (int i = 1; i < n; ++i)
	{
		const int key = array[i];
		int j = i - 1;
		for ( ;(j >= 0) && (array[j] > key); --j)
			array[j + 1] = array[j];
		array[j + 1] = key;
		output(array);
	}

	return 0;
}
