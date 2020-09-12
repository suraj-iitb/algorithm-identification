#include <iostream>
using namespace std;

void trace(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
}

int bubbleSort(int a[], int n){
    int flag = 1, count = 0;
    while(flag){
        flag = 0;
        for(int j = n - 1; j > 0; j--){
            if(a[j - 1] > a[j]){
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                flag = 1;
                count++;
            }
        }
    }

    return count;
}

int main(void){
    int n, a[100], c;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    c = bubbleSort(a, n);
    trace(a, n);
    cout << c << endl;

    return 0;
}
