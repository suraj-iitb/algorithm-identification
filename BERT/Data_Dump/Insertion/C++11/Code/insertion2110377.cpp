#include <iostream>
#include <cstdlib>
using namespace std;

void InsertSort(int x[], int N);

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
    InsertSort(x, N);

    return 0;
}

void InsertSort(int x[], int N){
    int tmp, j, k;

    for(int i = 1; i < N; i++){
        for(k = 0; k < N - 1; k++){
            cout << x[k] << " ";
        }
        cout << x[k] << endl;
        tmp = x[i];
        j = i - 1;
        while(j >= 0 && x[j] > tmp){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = tmp;

    }
    for(k = 0; k < N - 1; k++){
        cout << x[k] << " ";
    }
    cout << x[k] << endl;
}
