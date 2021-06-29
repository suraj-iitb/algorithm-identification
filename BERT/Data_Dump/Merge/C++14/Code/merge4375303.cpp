#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define INFTY INT_MAX
#define MAX 500000

int compCount;

void merge(int* s, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int *l, *r;
    l = new int[n1+1];
    r = new int[n2+1];

    for (int i = 0; i < n1; i++)
        l[i] = s[left + i];
    for (int i = 0; i < n2; i++)
        r[i] = s[mid + i];
    
    l[n1] = r[n2] = INFTY;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (l[i] <= r[j]) {
            s[k] = l[i];
            i++;
        } else {
            s[k] = r[j];
            j++;
        }
        compCount++;
    }
    delete [] l;
    delete [] r;
}

void mergeSort(int* s, int left, int right)
{
    if (left + 1 >= right) return;
    int mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
}

int main(int, char**)
{
    int n;
    int *s;
    s = new int[MAX];
    compCount = 0;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    mergeSort(s, 0, n);
    for (int i = 0; i < n; i++)
        if (i < n-1) cout << s[i] << " ";
        else cout << s[i] << endl; 
    cout << compCount << endl;
    delete [] s;

    return 0;
}
