#include<iostream>

using namespace std;
const int N = 500005, INF = 1e9+7;
long long sum = 0;
void merge(int A[], int p, int q, int r){
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[N], R[N];
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[q + i + 1];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
            sum++;
        }
        else 
        {
            A[k] = R[j];
            j++;
            sum++;
        }
    }    
}

void merge_sort(int A[], int p,int r){
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(){
    int A[500005];
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    merge_sort(A, 0, n-1);
    for (int i = 0; i < n-1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[n-1];
    cout << "\n" << sum << endl;
}
