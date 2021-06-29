//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=10029 の代わりにここでテスト
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               
//                                                               

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i==n-1];
    return 0;
}
