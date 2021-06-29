#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        int mini = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j] < a[mini]) {
                mini = j;
            }
        }
        swap(a[mini], a[i]);
        if (mini != i)
            ++cnt;
    }
    ostringstream os;
    for_each(a.begin(), a.end() - 1,
             [&os](const int& e){
                 os << e << " ";
             });
    os << *(a.end() - 1);
    cout << os.str() << endl;
    cout << cnt << endl;
    return 0;
}

