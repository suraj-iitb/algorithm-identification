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

	int gCount = 0;

	void Merge(std::vector<int>& seq, int left, int mid, int right)
	{
		static const int kMaxSize = 500000;
		static int LEFT[kMaxSize / 2 + 2];
		static int RIGHT[kMaxSize / 2 + 2];

		int left_num = mid - left;
		int right_num = right - mid;

		for (int i = 0; i < left_num; ++i)
		{
			LEFT[i] = seq[left + i];
		}
		for (int i = 0; i < right_num; ++i)
		{
			RIGHT[i] = seq[mid + i];
		}
		LEFT[left_num] = std::numeric_limits<int>::max();
		RIGHT[right_num] = std::numeric_limits<int>::max();
		
		int left_index = 0;
		int right_index = 0;
		for (int i = left; i < right; ++i)
		{
			++gCount;
			if (LEFT[left_index] <= RIGHT[right_index])
			{
				seq[i] = LEFT[left_index++];
			}
			else
			{
				seq[i] = RIGHT[right_index++];
			}
		}
	}

	void MergeSort(std::vector<int>& seq, int left, int right)
	{
		if (1 < right - left)
		{
			int mid = (left + right) / 2;
			MergeSort(seq, left, mid);
			MergeSort(seq, mid, right);
			Merge(seq, left, mid, right);
		}
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

	MergeSort(sequence, 0, num);

	PrintLine(sequence);
	std::cout << gCount << std::endl;
}

