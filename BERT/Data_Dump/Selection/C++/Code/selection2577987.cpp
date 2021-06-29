#include <vector>
#include <iostream>

using namespace std;

int sort(vector<int>& v)
{
        int cnt = 0;

        for (size_t i = 0; i < v.size(); i++) {
                unsigned int min = i;
                for (size_t j = i; j < v.size(); j++) {
                        if (v[j] < v[min]) {
                                min = j;
                        }
                }
                if (min != i) {
                        int tmp = v[min];
                        v[min] = v[i];
                        v[i] = tmp;
                        cnt++;
                }
        }
        return cnt;
}

int main()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
                cin >> v[i];
        }
        int cnt = sort(v);
        for (int i = 0; i < n; i++) {
                cout << v[i];
                if (i < n - 1) {
                        cout << ' ';
                } else {
                        cout << '\n';
                }
        }
        cout << cnt << '\n';
}
