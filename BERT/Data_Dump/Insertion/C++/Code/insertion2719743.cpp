#include <iostream>
#include <numeric>
using namespace std;

void insertSort(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        int j = i - 1;
        
        while(0 <= j && a[j] > v) {
            a[j+1] = a[j];
            --j;
        }
        a[j + 1] = v;
        
        for (int k = 0; k < n; ++k)
            cout << ((k==0)? "" : " ") << a[k];
        cout << endl;
    }
    
}

int main(void)
{
    int a[100], n;
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
        
    insertSort(a, n);
    
    return 0;
}
