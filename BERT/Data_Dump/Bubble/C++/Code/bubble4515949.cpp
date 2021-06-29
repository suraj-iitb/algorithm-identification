#include<bits/stdc++.h>

using namespace std;

int nums[105];

void trace(int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[n - 1]);
}

int cnt;

void bubble_sort(int n) {
    bool flag = false;
    int begin = 0;
    for (int j = 0; j < n - 1; ++j) {
        for (int i = n - 1; i > begin; --i) {
            if (nums[i] < nums[i - 1]) {
                int tmp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = tmp;
                ++cnt;
            }
        }
        ++begin;
    }
}

int main() {
#ifdef TEST
    freopen("input", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if(1 == n) {
        printf("%d\n", nums[0]);
        cout << "0" << endl;
    } else {
        bubble_sort(n);
        trace(n);
        cout << cnt << endl;
    }

    return 0;
}

