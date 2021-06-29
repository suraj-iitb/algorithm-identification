#include <iostream>
using namespace std;

void print_array(int* a, int n){
    for (int i = 0; i < n; i++){
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main (){
    int n;

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    print_array(a, n);

    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        print_array(a, n);
    }

    return 0;
}
