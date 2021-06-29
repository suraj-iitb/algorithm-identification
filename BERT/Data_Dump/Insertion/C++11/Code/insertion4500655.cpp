# include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
    
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) printf(" %d", a[i]);
    printf("\n");
    
    for (int i = 0; i < n - 1; ++i) {
        int sort_idx = i + 1;
        
        for (int j = i; j >= 0; --j) {
            if (a[sort_idx] < a[j]) {
                swap(a[sort_idx], a[j]);
                sort_idx = j;
            }
            else break;
        }
        
        printf("%d", a[0]);
        for (int i = 1; i < n; ++i) printf(" %d", a[i]);
        printf("\n");
    }
    
    return 0;
}
