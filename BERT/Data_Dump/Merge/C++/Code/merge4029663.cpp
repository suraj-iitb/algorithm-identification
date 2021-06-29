#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const int MAX_S = 500000;

int tmp[MAX_S];

int merge_sort(const int N, int start, int end, int (*s)[MAX_S]) {
    int count = 0;

    assert(end - start >= 0);
    if (end - start == 0 || end - start == 1) {
        return count;
    }

    int mid = (start + end) / 2;
    count += merge_sort(N, start, mid, s);
    count += merge_sort(N, mid, end, s);

    int ti = 0;
    int left = start;
    int right = mid;
    while (left < mid && right < end) {
        if ((*s)[left] < (*s)[right]) {
            tmp[ti] = (*s)[left];
            left++;
            ti++;
        } else {
            tmp[ti] = (*s)[right];
            right++;
            ti++;
        }
        count++;
    }
    while (left < mid) {
        tmp[ti] = (*s)[left];
        left++;
        ti++;
        count++;
    }
    while (right < end) {
        tmp[ti] = (*s)[right];
        right++;
        ti++;
        count++;
    }

    for (int i = 0; i < end - start; i++) {
        (*s)[start + i] = tmp[i];
    }

    return count;
}

int main(void) {
    int N;
    cin >> N;

    int s[MAX_S];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    int count = merge_sort(N, 0, N, &s);

    cout << s[0];
    for (int i = 1; i < N; i++) {
        cout << " " << s[i];
    }
    cout << endl;

    cout << count << endl;

    return 0;
}

