#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 600000
#define INFTY 2000000000

int merge(vector<int>& vec, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> vec_L;
    vector<int> vec_R;
    vec_L.reserve(n1 + 1);
    vec_R.reserve(n2 + 1);

    for (int i = 0; i < n1; i++)
    {
        vec_L[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        vec_R[i] = vec[mid + i];
    }
    vec_L[n1] = INFTY;
    vec_R[n2] = INFTY;
    int i = 0;
    int j = 0;
    int cnt = 0;
    for (int k = left; k < right; k++)
    {
        if (vec_L[i] <= vec_R[j]) {
            vec[k] = vec_L[i];
            i++;
        } else {
            vec[k] = vec_R[j];
            j++;
        }
        cnt++;
    }
    return cnt;
}
void merge_sort(vector<int>& vec, int left, int right, int& cnt)
{
    int mid = 0;
    if (left+1 < right)
    {
        mid = (left + right) / 2;
        merge_sort(vec, left, mid, cnt);
        merge_sort(vec, mid, right, cnt);
        cnt += merge(vec, left, mid, right);
    }
}

int main()
{
    vector<int> vec;
    vec.reserve(MAX);
    int n = 0;
    int m = 0;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        vec.push_back(m);
    }

    int cnt = 0;
    merge_sort(vec, 0, n, cnt);

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d\n", vec[i]);
        }
        else
        {
            printf("%d ", vec[i]);
        }
    }
    printf("%d\n", cnt);
}
