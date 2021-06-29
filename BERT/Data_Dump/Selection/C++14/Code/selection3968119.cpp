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

	int GetValue(std::istream& stream)
	{
		int in;
		stream >> in;

		return in;
	}
}

int main(int argc, char* argv[])
{
	auto file = (argc == 1) ? std::ifstream() : std::ifstream(argv[1]);
	std::istream& stream = (argc == 1) ? std::cin : file;

	int num = GetValue<1>(stream)[0];
	std::vector<int> values = GetValue(stream, num, ' ');
	int count = 0;

	for (int i = 0; i < num - 1; ++i)
	{
		int min_index = i;

		for (int j = i; j < num - 1; ++j)
		{
			if (values[min_index] > values[j + 1])
			{
				min_index = j + 1;
			}
		}

		if (i != min_index)
		{
			++count;
			std::swap(values[i], values[min_index]);
		}
	}

	std::cout << values[0];
	for (size_t i = 1; i < values.size(); ++i)
	{
		std::cout << ' ' << values[i];
	}

	std::cout << '\n' << count << std::endl;
}

