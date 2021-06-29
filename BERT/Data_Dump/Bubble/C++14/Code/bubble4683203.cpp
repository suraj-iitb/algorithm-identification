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

using namespace std;

int bubble_sort(int A[], int N) {
    int count = 0;
	for (int i = 1; i < N; ++i) {
		bool flag = true;
		while (flag) {
            flag = false;
			for (int j = N - 1; j > 0; --j) {
				int tmp = A[j - 1];
				if (A[j] < tmp) {
					A[j - 1] = A[j];
					A[j] = tmp;
					flag = true;
                    ++count;
				}
			}
		}
	}
    return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A[100] = {};
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int count = bubble_sort(A, N);
    for(int i = 0; i < N; ++i){
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << "\n";
    cout << count << "\n";
	return 0;
}
