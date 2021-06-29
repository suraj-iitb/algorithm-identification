#include <cstdio>
#include <vector>

int count = 0;
void mergeSort(std::vector<int> &a, std::vector<int> &b, int left, int right){
    if(left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(a, b, left, mid);
    mergeSort(a, b, mid + 1, right);

    int i = left;
    int j = mid + 1;
    for(int k = left; k <= right; ++k){
        if(i > mid) b[k] = a[j++];
        else if(j > right) b[k] = a[i++];
        else if(a[i] <= a[j]){
            b[k] = a[i++];
        } else if(a[i] > a[j]){
            b[k] = a[j++];
        }
    }
    count += right - left  + 1;
    for(int k = left; k <= right; ++k){
        a[k] = b[k];
    }
}

int main(){
    int n;
    std::scanf("%d", &n);

    std::vector<int> a(n, 0);
    std::vector<int> b(n, 0);
    for(int i = 0; i < n; ++i){
        std::scanf("%d", &a[i]);
    }

    mergeSort(a, b, 0, n - 1);
    std::printf("%d", a[0]);
    for(int i = 1; i < n; ++i){
        std::printf(" %d", a[i]);
    }
    std::printf("\n");
    std::printf("%d\n", count);
    return 0;
}
