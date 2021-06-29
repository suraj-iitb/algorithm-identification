#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <limits>
#include <fstream>
#include <numeric>

namespace
{
	template<int N>
	std::array<int, N> GetValue(std::istream& stream)
	{
		std::string buf;
		std::getline(stream, buf);

		std::stringstream sstr(buf);
		std::array<int, N> retval;

		for (int i = 0; i < N; ++i)
		{
			std::getline(sstr, buf, ' ');
			retval[i] = std::stoi(buf);
		}

		return retval;
	}

	std::vector<int> GetValue(std::istream& stream, int num, char delim)
	{
		std::string buf;
		std::vector<int> retval;
		retval.reserve(num);

		for (int i = 0; i < num; ++i)
		{
			std::getline(stream, buf, delim);
			retval.push_back(std::stoi(buf));
		}

		return retval;
	}

	void Print(const std::vector<int>& values)
	{
		std::cout << values[0];

		auto f = [](int e) {std::cout << ' ' << e; };

		std::for_each(values.begin() + 1, values.end(), f);

		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	//auto file = (argc == 1) ? std::ifstream() : std::ifstream(argv[1]);
	//std::istream& stream = (argc == 1) ? std::cin : file;
	std::istream& stream = std::cin;

	auto num = GetValue<1>(stream);

	std::vector<int> values = GetValue(stream, num[0], ' ');

	Print(values);

	for (int i = 1; i < num[0]; ++i)
	{
		int v = values[i];
		int j = i - 1;

		while (0 <= j && v < values[j])
		{
			values[j + 1] = values[j];
			--j;
		}

		values[j + 1] = v;

		Print(values);
	}
}

