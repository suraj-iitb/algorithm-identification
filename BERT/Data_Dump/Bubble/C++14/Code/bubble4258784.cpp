//include
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <sstream>
#include <utility>
//マクロとか
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n) + 1; i++)
#define all(vecto) vecto.begin(), vecto.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
using ll = long long;

//自前の関数たち
//最大公約数
ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

//最小公倍数
ll LCM(ll a, ll b)
{
    return (a * b) / GCD(a, b);
}

//namespace my
namespace my
{
//配列の最大値or最小値を数値で返す関数
int max_element(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    return vec.at(vec.size() - 1);
}
int min_element(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    return vec.at(0);
}
} // namespace my

//yes,noを出力するやつ
void ans(bool qus)
{
    if (qus == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

void Ans(bool qust)
{
    if (qust == true)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

//std名前空間を使用
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//スタート

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n){
        cin >> vec[i];
    }

    bool flag = true;
    int count = 0;
    int j = 0;
    while (flag)
    {
        flag = false;
        for (int i = n - 1; i > j; i--){
            if (vec[i] < vec[i - 1]){
                swap(vec[i], vec[i - 1]);
                count++;
                flag = true;
            }
        }
        j++;
    }
    rep(i,n){
        if(i<n-1){
            cout << vec[i] << ' ';
        }
        else
        {
            cout << vec[i] << endl;
        }
        
    }
    cout << count << endl;
}
