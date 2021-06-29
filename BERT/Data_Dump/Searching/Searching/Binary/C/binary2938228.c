#include <stdio.h>

// positive only
int get_int() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return -1;
    while(47 < c && c < 58) {
        n = 10 * n + (c & 0xf);
        c = getchar_unlocked();
    }
    return n;
}
// arr should be sorted
void *binary_search(const int key, const int *arr, const int N){
    int left = 0;
    int right = N;
    int mid;
    while(left < right) {
        mid = left + ((right - left) / 2);
        if(arr[mid] == key) return (void *)(arr + mid);
        else if(arr[mid] > key) right = mid;
        else left = mid + 1;
    }
    return NULL;
}
int main(int argc, char **argv) {
    int n = get_int();
    int s[100001];
    for(int i = 0; i < n; ++i) {
        s[i] = get_int();
    }
    int q = get_int();
    int cnt = 0;
    int t;
    while(q--) {
        binary_search(get_int(), s, n) && cnt++;
    }
    printf("%d\n", cnt);
}

