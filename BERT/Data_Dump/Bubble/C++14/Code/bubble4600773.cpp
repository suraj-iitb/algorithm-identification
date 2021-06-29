#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void print_a() {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << " ";
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

    int num = 0;

    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
                num++;
            }
        }
    }

    print_a();
    cout << endl << num << endl;

    return 0;
}

