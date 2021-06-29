#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
typedef long long ll;
typedef vector<ll> vll;
//typedef pow(2,31)+1 INF;

int cnt;

string to_binString(ll n){
    string bins = "";
    ll size = log2(n);
    for(int i=size;i>=0;i--){
        if(pow(2,i) <= n){
            n -= pow(2,i);
            bins += '1';
        }
        else bins += '0'; 
    }
    return bins;
}

void merge(int n[], int left, int mid, int right)
{
    int num = right - left;
    int *tmp = new int[num];

    int iw = 0;
    int il = left;
    int ir = mid;

    while (il < mid && ir < right)
    {
        if (n[il] <= n[ir])
        {
            tmp[iw++] = n[il++];
        } else {
            tmp[iw++] = n[ir++];
        }
    }

    while (il < mid) tmp[iw++] = n[il++];
    while (ir < right) tmp[iw++] = n[ir++];

    for (int i=0; i<num; i++){
        n[left + i] = tmp[i];
        cnt++;
    }

    delete[] tmp;
}

void merge_sort_sub(int n[], int left, int right)
{
    if (right - left <= 1) return;

    int mid = left + (right - left) / 2;
    merge_sort_sub(n, left, mid);
    merge_sort_sub(n, mid, right);

    merge(n, left, mid, right);
}


void merge_sort(int n[], int len)
{
    merge_sort_sub(n, 0, len);
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    rep(i,n)cin >> A[i];

    merge_sort(A, n);

    rep(i,n){
        cout << A[i];
        if(i != n-1)cout << " ";
        else cout << endl;
    }
    cout << cnt << endl;
    
    return 0;
}
