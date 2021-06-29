#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) 
                mini = j;
        }
        if (mini != i) {
            swap(arr[i], arr[mini]);
            ++swaps;
        }
    }
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("%d\n%d\n", arr[n - 1], swaps);
    return 0;
}
