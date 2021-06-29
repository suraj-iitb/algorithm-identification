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
int selectionSort(Container& container)
{
    int count(0);

    for(auto it(begin(container)); it != end(container); ++it)
    {
        auto kt(it);

        for(auto jt(it); jt != end(container); ++jt)
        {
            if(*kt > *jt) kt = jt;
        }

        iter_swap(it, kt);
        
        if(it != kt) ++count;
    }

    return count;
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

    int count(selectionSort(v));

    print(v);

    cout << count << endl;

    return 0;
}
