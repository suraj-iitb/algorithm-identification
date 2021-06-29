#include <iostream>
using namespace std;

const int k = 2000000;

void CountingSort(int *a, int *b, int k, int n)
{
    int c[k] = {0};

    for (int i = 0; i < n; i++)
        c[a[i]]++;
    
    for (int i = 0; i < k; i++)
        c[i+1] = c[i+1] + c[i];
    
    for (int i = n-1; i >= 0; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n] = {0};

    CountingSort(a, b, k, n);

    for (int i = 1; i <= n; i++) {
        if (i!=1) {
            cout << ' ';
            cout << b[i];
        }
        else 
            cout << b[i];
        
    }
    cout << endl;
    return 0;
}
