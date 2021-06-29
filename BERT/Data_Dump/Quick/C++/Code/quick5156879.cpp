#include <iostream>
using namespace std;

int Partition(pair<char, int> *a, int left, int right)
{
    int i = left-1;
    for(int j=left; j<right; j++)
    {
        if(a[j].second<=a[right-1].second)
        {
            i++;
            pair<char, int> temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return i;
}

void QuickSort(pair<char, int> *a, int left, int right)
{
    if(left<right)
    {
        int mid = Partition(a, left, right);
        QuickSort(a, left, mid);
        QuickSort(a, mid+1, right);
    }
}

void Merge(pair<char, int> *a, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid-left;
    int n2 = right-mid;
    pair<char, int> b1[n1+1];
    pair<char, int> b2[n2+1];
    for(i=0; i<n1; i++)
        b1[i] = a[i+left];
    for(i=0; i<n2; i++)
        b2[i] = a[i+mid];
    b1[n1].second = 2000000000;
    b2[n2].second = 2000000000;
    i = 0;
    j = 0;
    for(k=left; k<right; k++)
    {
        if(b1[i].second<=b2[j].second)////////////
            a[k] = b1[i++];
        else
            a[k] = b2[j++];
    }
}

void MergeSort(pair<char, int> *a, int left, int right)
{
    if(left+1<right)
    {
        int mid = (left+right)/2;
        MergeSort(a, left, mid);
        MergeSort(a, mid, right);
        Merge(a, left, mid, right);
    }
}

int isStable(pair<char, int> *a, pair<char, int> *b, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i].first!=b[i].first)
            return 0;
    }
    return 1;
}

int main(void)
{
    int i, n;
    cin>>n;
    pair<char, int> a[n], b[n];
    for(i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;
    for(i=0; i<n; i++)
        b[i] = a[i];
    QuickSort(a, 0, n);
    MergeSort(b, 0, n);
    if(isStable(a, b, n))
        cout<<"Stable"<<endl;
    else
        cout<<"Not stable"<<endl;
    for(i=0; i<n; i++)
        cout<<a[i].first<<' '<<a[i].second<<endl;
    return 0;
}
