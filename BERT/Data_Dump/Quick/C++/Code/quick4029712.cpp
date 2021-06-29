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

const int MAX_N = 100000;

struct card {
    char mark;
    int value;
};

void merge_sort(const int N, int start, int end, struct card (*s)[MAX_N]) {
    static struct card tmp[MAX_N];

    assert(end - start >= 0);
    if (end - start == 0 || end - start == 1) {
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(N, start, mid, s);
    merge_sort(N, mid, end, s);

    int ti = 0;
    int left = start;
    int right = mid;
    while (left < mid && right < end) {
        if ((*s)[left].value <= (*s)[right].value) {
            tmp[ti] = (*s)[left];
            left++;
            ti++;
        } else {
            tmp[ti] = (*s)[right];
            right++;
            ti++;
        }
    }
    while (left < mid) {
        tmp[ti] = (*s)[left];
        left++;
        ti++;
    }
    while (right < end) {
        tmp[ti] = (*s)[right];
        right++;
        ti++;
    }

    for (int i = 0; i < end - start; i++) {
        (*s)[start + i] = tmp[i];
    }
}

void quick_sort(const int N, int start, int end, struct card (*cards)[MAX_N]) {
    assert(end - start >= 0);
    if (end - start == 0 || end - start == 1) {
        return;
    }

    int pivot = end - 1;
    int border = start;
    for (int i = start; i < pivot; i++) {
        if ((*cards)[i].value <= (*cards)[pivot].value) {
            swap((*cards)[i], (*cards)[border]);
            border++;
        }
    }
    swap((*cards)[border], (*cards)[pivot]);

    quick_sort(N, start, border, cards);
    quick_sort(N, border + 1, end, cards);
}

int main(void) {
    int N;
    cin >> N;

    struct card cards1[MAX_N];
    struct card cards2[MAX_N];
    for (int i = 0; i < N; i++) {
        cin >> cards1[i].mark;
        cin >> cards1[i].value;
        cards2[i] = cards1[i];
    }

    quick_sort(N, 0, N, &cards1);
    merge_sort(N, 0, N, &cards2);

    bool is_stable = true;
    for (int i = 0; i < N; i++) {
        if (cards1[i].mark != cards2[i].mark || cards1[i].value != cards2[i].value) {
            is_stable = false;
            break;
        }
    }
    if (is_stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    cout << cards1[0].mark << " " << cards1[0].value << endl;
    for (int i = 1; i < N; i++) {
        cout << cards1[i].mark << " " << cards1[i].value << endl;
    }

    return 0;
}

