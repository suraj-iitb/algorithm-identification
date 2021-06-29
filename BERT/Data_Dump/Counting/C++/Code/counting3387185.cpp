#include <cstdio>
#include <vector>

int main(){
    int n;
    std::scanf("%d", &n);
    std::vector<int> a(n, 0);
    std::vector<int> b(n, 0);
    int maxval = 0;
    for(int i = 0; i < n; ++i){
        std::scanf("%d", &a[i]);
        maxval = std::max(maxval, a[i]);
    }
    std::vector<int> c(maxval, 0);
    for(int i = 0; i < n; ++i){
        c[a[i]]++;
    }
    for(int i = 1; i <= maxval; ++i){
        c[i] += c[i - 1];
    }
    for(int i = n - 1; i >= 0; --i){
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    std::printf("%d", b[0]);
    for(int i = 1; i < n; ++i){
        std::printf(" %d", b[i]);
    }
    std::printf("\n");
}
