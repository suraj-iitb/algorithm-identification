#include <iostream>
#include <vector>

constexpr int SENTINEL = 1000000001;
int cnt = 0;

void Merge(std::vector<int> &S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<int> L, R;
    for (auto i=0; i<n1; ++i) L.push_back(S[left+i]);
    for (auto i=0; i<n2; ++i) R.push_back(S[mid+i]);
    L.push_back(SENTINEL);
    R.push_back(SENTINEL);
    int i{0}, j{0};
    for (auto k=left; k<right; ++k) {
        if (L[i] <= R[j]) {
            S[k] = L[i];
            ++i;
            ++cnt;
        } else {
            S[k] = R[j];
            ++j;
            ++cnt;
        }
    }
}

void MergeSort(std::vector<int> &S, int left, int right) {
    if ((left+1) < right) {
        int mid = (left + right) / 2;
        MergeSort(S, left, mid);
        MergeSort(S, mid, right);
        Merge(S, left, mid, right);
    }
}

int main() {
    int n, temp;
    std::cin >> n;
    
    std::vector<int> S;
    for (auto i=0; i<n; ++i) {
        std::cin >> temp;
        S.push_back(temp);
    }
    
    MergeSort(S, 0, n);
    for (auto i=0; i<n; ++i) {
        std::cout << S[i];
        if (i != (n-1)) 
            std::cout << " ";
        else 
            std::cout << std::endl;
    }
    std::cout << cnt << std::endl;
}
