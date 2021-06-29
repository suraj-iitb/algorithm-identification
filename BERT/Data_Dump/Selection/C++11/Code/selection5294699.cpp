#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", a[i]);
        else printf(" %d", a[i]);
    }
    cout << endl;
}

int selection_sort(vector<int> &a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[mini]) mini = j;
        }
        if (i == mini) continue;
        int tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
        cnt++;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = selection_sort(a, n);
    show(a, n);
    cout << cnt << endl;
    return 0;
}

