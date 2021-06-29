#include<bits/stdc++.h>

using namespace std;

int nums[105];

void trace(int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[n - 1]);
}

void insert_sort(int n) {
    for (int i = 1; i < n; ++i) {
        int tmp = nums[i];
        int j = i;
        while(j > 0 && tmp < nums[j - 1]) {
            nums[j] = nums[j - 1];
            --j;
        }
        nums[j] = tmp;
        trace(n);
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
    } else {
        trace(n);
        insert_sort(n);
    }

    return 0;
}

