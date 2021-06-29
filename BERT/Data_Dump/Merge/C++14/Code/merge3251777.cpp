#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cnt = 0;

void merge(vector<int>& S, int left, int mid, int right)
{
    int n_1 = mid - left;
    int n_2 = right - mid;

    vector<int> L = vector<int>(n_1 + 1);
    vector<int> R = vector<int>(n_2 + 1);

    copy(S.begin() + left, S.begin() + mid, L.begin());
    L[n_1] = INT_MAX;
    copy(S.begin() + mid, S.begin() + right, R.begin());
    R[n_2] = INT_MAX;

    int i, j, k;
    for (i = 0, j = 0, k = left; k < right; k++){
        if (L[i] < R[j]) S[k] = L[i++];
        else S[k] = R[j++];
    }

    cnt += right - left;
}

void merge_sort(vector<int>& S, int left, int right)
{
    if (left + 1 < right){
        int mid = (left + right) / 2;

        merge_sort(S, left, mid);
        merge_sort(S, mid, right);
        merge(S, left, mid, right);
    }
}

int main()
{
    int n;
    vector<int> S;

    cin >> n;
    S = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> S[i];

    merge_sort(S, 0, n);

    bool first = true;
    for (int num : S){
        if (first)  first = false;
        else printf(" ");

        printf("%d", num);
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}


