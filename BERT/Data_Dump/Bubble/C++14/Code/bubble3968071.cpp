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
	bool flag = true;
	int count = 0;

	while (flag)
	{
		flag = false;

		for (int i = num - 1; i > 0; --i)
		{
			if (values[i] < values[i - 1])
			{
				flag = true;
				++count;
				std::swap(values[i], values[i - 1]);
			}
		}
	}

	std::cout << values[0];
	for (size_t i = 1; i < values.size(); ++i)
	{
		std::cout << ' ' << values[i];
	}

	std::cout << '\n' << count << std::endl;
}

