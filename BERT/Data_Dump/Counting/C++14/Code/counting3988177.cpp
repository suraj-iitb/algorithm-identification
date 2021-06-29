#define _USE_MATH_DEFINES

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
#include <stack>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_set>
#include <cmath>
#include <iomanip>

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
		std::getline(stream, buf);
		std::stringstream sstr(buf);

		std::vector<int> retval;
		retval.reserve(num);

		std::string input;;
		for (int i = 0; i < num && std::getline(sstr, input, delim); ++i)
		{
			retval.push_back(std::stoi(input));
		}

		return retval;
	}

	int GetValue(std::istream& stream)
	{
		int in;
		stream >> in;

		return in;
	}

	std::vector<std::string> GetValueString(std::istream& stream, int num, char delim)
	{
		std::string buf;
		std::vector<std::string> retval;
		retval.reserve(num);

		std::getline(stream, buf);
		std::stringstream sstr(buf);

		for (int i = 0; i < num && std::getline(sstr, buf, delim); ++i)
		{
			retval.push_back(std::move(buf));
		}

		return retval;
	}

	template<typename T>
	void PrintLine(const std::vector<T>& sequence)
	{
		std::cout << sequence[0];

		for (size_t i = 1; i < sequence.size(); ++i)
		{
			std::cout << ' ' << sequence[i];
		}

		std::cout << std::endl;
	}

	template<typename T>
	void Print(const std::vector<T>& sequence)
	{
		for (const auto& e : sequence)
		{
			std::cout << e << '\n';
		}

		std::cout << std::flush;
	}
}

int main(int argc, char* argv[])
{
	auto file = (argc == 1) ? std::ifstream() : std::ifstream(argv[1]);
	std::istream& stream = (argc == 1) ? std::cin : file;
	if (argc == 1)
	{
		std::cin.tie(0);
		std::ios::sync_with_stdio(false);
	}

	int num = GetValue<1>(stream)[0];
	std::vector<int> sequence =
		GetValue(stream, num, ' ');
	std::vector<int> result(num);

	const int kMax = 10001;
	int ar[kMax] = {};
	//int result[2000000];

	for (int e : sequence)
	{
		++ar[e];
	}

	for (int i = 1; i < kMax; ++i)
	{
		ar[i] += ar[i - 1];
	}

	for (auto itr = sequence.rbegin(); itr != sequence.rend(); ++itr)
	{
		result[ar[*itr] - 1] = *itr;
		--ar[*itr];
	}

	std::cout << result[0];
	for (int i = 1; i < num; ++i)
	{
		std::cout << ' ' << result[i];
	}
	std::cout << std::endl;
}

