#include <iostream>

using namespace std;

int  selectionSort(int a[],int n) 
{
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        swap(a[i], a[minj]);
        if (i != minj) {
            count++;
        }
        
    }
    return count;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sw = selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
