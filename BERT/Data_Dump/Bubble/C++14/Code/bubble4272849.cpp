#include <iostream>
using namespace std;

int swapCount;

// N 個の要素を含む 0-オリジンの配列 A
void bubbleSort(int a[], int n){
    bool flag = true;  // 逆の隣接要素が存在する
    while(flag){
        flag = false;
        for(int j=n-1; j>0; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                swapCount++;
                flag = true;
            }
        }
    }
}

void print(int a[], int n){
    for(int i=0; i<n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

int main(void){
    int n;
    cin >> n;
    int a[110];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    swapCount = 0;
    bubbleSort(a, n);

    print(a, n);

    cout << swapCount << endl;
    return 0;
}
