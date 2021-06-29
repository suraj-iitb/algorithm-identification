#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void BubbleSort(int x[], int N);
void trace(int x[], int N);

int main(){
    int N, i;
    string buf;

    cin >> buf;
    N = stoi(buf);

    int x[N];

    for(i = 0; i < N; i++){
        cin >> buf;
        x[i] = stoi(buf);
    }
    BubbleSort(x, N);

    return 0;
}

void BubbleSort(int x[], int N){
    int i, flag, num = 0;

    flag = 1;
    while(flag){
        flag = 0;
        for(i = N - 1; i > 0; i--){
            if(x[i] < x[i - 1]){
                swap(x[i], x[i - 1]);
                num++;
                flag = 1;
            }
        }
    }
    trace(x, N);
    cout << num << endl;
}

void trace(int x[], int N){
    int k;

    for(k = 0; k < N - 1; k++){
        cout << x[k] << " ";
    }
    cout << x[k] << endl;
}
