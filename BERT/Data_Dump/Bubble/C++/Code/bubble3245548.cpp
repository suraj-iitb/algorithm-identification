#include <iostream>

using namespace std;
int bubbleSort(int a[], int n){
    int s = 0;
    int j = 0;
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > 0; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                s++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (i != n-1)
            cout << a[i] << " ";
        else
            cout << a[i] << endl;
    }
    cout << s << endl;
}
int main()
{
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a,n);
    return 0;
}

