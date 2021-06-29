#include <cstdio>
#include <vector>
#include <utility>
using Card = std::pair<char, int>;

int partition(std::vector<Card> &a, int p, int r){
    Card x = a[r];
    int i = p - 1;
    for(int j = p; j < r; ++j){
        if(a[j].second <= x.second) std::swap(a[++i], a[j]);
    }
    int m = i + 1;
    std::swap(a[m], a[r]);
    return m;
}

void qsort(std::vector<Card> &a, int p, int r){
    if(p >= r) return;
    int m = partition(a, p, r);
    qsort(a, p, m - 1);
    qsort(a, m + 1, r);
}

void msort(std::vector<Card> &a, std::vector<Card> &b, int p, int r){
    if(p >= r) return;
    int m = p + (r - p) / 2;
    msort(a, b, p, m);
    msort(a, b, m + 1, r);

    int i = p;
    int j = m + 1;
    for(int k = p; k <= r; ++k){
        if(i > m) b[k] = a[j++];
        else if(j > r) b[k] = a[i++];
        else if(a[i].second <= a[j].second) b[k] = a[i++];
        else if(a[i].second > a[j].second) b[k] = a[j++];
    }
    for(int k = p; k <= r; ++k){
        a[k] = b[k];
    }
}

int main(){
    int n;
    std::scanf("%d", &n);
    Card np = std::make_pair(0, 0);
    std::vector<Card> a(n, np);
    std::vector<Card> b(n, np);
    for(int i = 0; i < n; ++i){
        char tmp[2];
        std::scanf("%s", tmp);
        a[i].first = tmp[0];
        std::scanf("%d", &a[i].second);
        b[i] = a[i];
    }
    qsort(a, 0, n - 1);
    std::vector<Card> c(n, np);
    msort(b, c, 0, n - 1);
    bool isStable = true;
    for(int i = 0; i < n; ++i){
	if(b[i].first != a[i].first){
            isStable = false;
            break;
        }
    }
    if(isStable)  std::printf("Stable\n");
    else std::printf("Not stable\n");
    for(int i = 0; i < n; ++i){
        std::printf("%c %d\n", a[i].first, a[i].second);
    }
    return 0;
}
