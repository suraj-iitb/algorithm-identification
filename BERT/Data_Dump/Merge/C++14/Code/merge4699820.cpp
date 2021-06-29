#pragma GCC optimize("Ofast")

#include <algorithm>      //sort,二分探索,など
#include <bitset>         //固定長bit集合
#include <cmath>          //pow,logなど
#include <complex>        //複素数
#include <deque>          //両端アクセスのキュー
#include <functional>     //sortのgreater
#include <iomanip>        //setprecision(浮動小数点の出力の誤差)
#include <iostream>       //入出力
#include <iterator>       //集合演算(積集合,和集合,差集合など)
#include <map>            //map(辞書)
#include <numeric>        //iota(整数列の生成),gcdとlcm(c++17)
#include <queue>          //キュー
#include <set>            //集合
#include <stack>          //スタック
#include <string>         //文字列
#include <unordered_map>  //イテレータあるけど順序保持しないmap
#include <unordered_set>  //イテレータあるけど順序保持しないset
#include <utility>        //pair
#include <vector>         //可変長配列
#include <list>           //双方向連結リスト

using namespace std;

constexpr int INF = numeric_limits<int>::max();

int merge(vector<int>& s, int left, int mid, int right){
    int cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for(int i = 0; i < n1; ++i){
        L[i] = s[left + i];
    }
    for(int i = 0; i < n2; ++i){
        R[i] = s[mid + i];
    }
    L[n1] = INF;
    R[n2] = INF;
    for(int k = left, i = 0, j = 0; k < right; ++k){
        ++cnt;
        if(L[i] <= R[j]){
            s[k] = L[i++];
        }else{
            s[k] = R[j++];
        }
    }
    return cnt;
}

int merge_sort(vector<int>& s, int left, int right){
    int cnt = 0;
    if(left + 1 < right){
        int mid = (left + right) / 2;
        cnt += merge_sort(s, left, mid);
        cnt += merge_sort(s, mid, right);
        cnt += merge(s, left, mid, right);
    }
    return cnt;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    int count = merge_sort(s, 0, n);
    for(int i = 0; i < n; ++i){
        if(i != 0) cout << " ";
        cout << s[i];
    }
    cout << "\n";
    cout << count << "\n";

	return 0;
}
