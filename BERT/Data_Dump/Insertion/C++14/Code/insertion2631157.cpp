#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <tuple>
#include <functional>
#include <limits>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// Print each element of a container.
template <typename Container>
void print(const Container& container)
{
    stringstream sstream;

    string delim("");
	for (const auto& element : container)
	{
		sstream << delim << element;
        delim = " ";
	}

    cout << sstream.str() << endl;
}

template <typename Container>
void insertionSort(Container& container)
{
    for(auto it(begin(container)); it != end(container); ++it)
    {
        auto key(*it);

        auto jt(it);
        while(jt != begin(container) && *prev(jt) > key)
        {
            *jt = *prev(jt);

            --jt;
        }

        *jt = key;

         print(container);
    }
}

int main()
{
    vector<int> v;

    int n;
    cin >> n;

    for(size_t i(0); i < n; ++i)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    insertionSort(v);

    return 0;
}
