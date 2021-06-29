#include <iostream>
using namespace std;

int bubbleSort(int a[], int N){
    int cnt = 0, v;
    bool flag = 1;
    for (int i = 0; flag; i++){
        flag = 0;
        for (int j = N - 1; j >= i+1; j--){
            if (a[j] < a[j-1]){
                v = a[j-1];
                a[j-1] = a[j];
                a[j] = v;
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

int main(){
    int a[100], N, cnt;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cnt = bubbleSort(a, N);
    for (int i = 0; i < N; i++){
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << cnt << endl;
}
