#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void print_a() {
    for (auto e : a) {
        cout << e;
        if (e != a.back()) cout << " ";
    }
}
int main() {
#ifdef LOCAL
    // 以降 cin の入力元が 'xxx.txt' になる
    std::ifstream in("aizu_code.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        print_a();
        cout << endl;
    }

    return 0;
}

