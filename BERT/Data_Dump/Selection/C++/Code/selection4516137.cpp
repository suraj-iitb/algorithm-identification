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

void select_sort(int n) {
    for (int j = 0; j < n - 1; ++j) {
        int index = j;
        for (int i = j + 1; i < n; ++i) {
            if(nums[index] > nums[i]) index = i;
        }
        if(index != j) {
            ++cnt;
            int tmp = nums[index];
            nums[index] = nums[j];
            nums[j] = tmp;
        }
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
        select_sort(n);
        trace(n);
        cout << cnt << endl;
    }

    return 0;
}

