#include <iostream>

using namespace std;
int selectionSort(int a[], int n){
    int s, m, flag;
    s = 0;
    for (int i = 0; i < n; i++){
        m = a[i];
        flag = i;
        for (int j = i+1; j < n; ++j){
            if (a[j] < m){
                m = a[j];
                flag = j;
            }
        }
        if (i != flag){
            swap(a[i], a[flag]);
            s++;
        }
    }
    return s;
}
int main()
{
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s = selectionSort(a, n);
    for (int i = 0; i < n; ++i){
        if (i != n-1)
            cout << a[i] << " ";
        else
            cout << a[i] << endl;
    }
    cout << s << endl;
    return 0;
}

