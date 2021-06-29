#include <iostream>
using namespace std;

void print(const int a[], const int n, const int count){
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << count << endl;
}

void selectionSort(int a[], int n){
    int count = 0;
    
    for(int i = 0; i < n; i++){
        int minj = i;
        int flag = 0;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
                flag = 1;
            }
        }

        int tmp;
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        if(flag == 1){
            count++;
        }
        //count++;
    }
    print(a, n, count);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    selectionSort(a, n);
    return 0;

}
