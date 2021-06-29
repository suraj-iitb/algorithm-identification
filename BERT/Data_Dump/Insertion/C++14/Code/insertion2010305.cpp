
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <fstream>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

constexpr int INF       = 1000000000;/* 1e+9a */
constexpr int MODULO    = 1000000007;

constexpr int evx[4] = { 1, 0, -1, 0 };
constexpr int evy[4] = { 0, 1, 0, -1 };

//----------------------------------
//----------------------------------
//

template<typename container>
inline void print_STL(container c)
{
        if(c.size() == 0)
                return;
        std::cout << c[0]; 
        for(int i = 1; i < c.size(); i++)
                std::cout << ' ' << c[i];
        std::cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
        int n;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++)
        {
                int tmp;
                cin >> tmp;
                nums.push_back(tmp);
        }
        print_STL(nums);
        for(int i = 1; i <n; ++i)
        {
                int key = nums[i];
                int j = i - 1;
                while(j >= 0 && nums[j] > key)
                {
                        nums[j+1] = nums[j];
                        j--;
                }
                nums[j+1] = key;

                print_STL(nums);
        }
}
