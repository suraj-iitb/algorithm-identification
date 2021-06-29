#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef struct card{
    char s;
    int v;
    int i;
}card;
 
card A[100000];
 
int partition(card A[], int p, int r);
void quickSort(card A[], int p, int r);
bool isStable(card A[], int n);
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)  {
        cin >> A[i].s >> A[i].v;
        A[i].i = i;
    }
 
    quickSort(A, 0, n - 1);
    if (isStable(A, n)) cout << "Stable\n";
    else cout << "Not stable\n";
 
    for (int i = 0; i < n; i++){
        cout << A[i].s << ' ' << A[i].v << '\n';
    }
 
    return 0;
}
 
int partition(card A[], int p, int r)
{
    int x = A[r].v;
    int i = p;
 
    for (int j = p; j < r; ++j)
    {
        if (A[j].v <= x){
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[i], A[r]);
    return i;
}
 
void quickSort(card A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
 
bool isStable(card A[], int n)
{
    for (int i = 1; i < n; i++) {
        if (A[i - 1].v == A[i].v && A[i - 1].i > A[i].i)
            return false;
    }
    return true;
}
