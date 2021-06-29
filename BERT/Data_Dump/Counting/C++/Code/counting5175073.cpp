#include<iostream>
using namespace std;

const int maxn = 2000001;
const int maxnum = 10001;
int n;
int a[maxn], b[maxn];
int c[maxnum];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];//输入，输出数组都是1起点，这样就还是输入了n个，a[n]已经提前申请好空间了
        c[a[i + 1]]++;
    }
    for (int i = 0; i < maxnum; i++) {
        c[i] += c[i - 1];//累加和
    }
    for (int i = n; i >= 1; i--) {//倒序选择，稳定排序
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}
