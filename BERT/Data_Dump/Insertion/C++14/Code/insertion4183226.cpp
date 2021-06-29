#include <iostream>
#include <algorithm>
using namespace std;

void printarr(int* a, int len){
    for(int i = 0; i < len - 1; i ++){
        cout << a[i] << " ";
    }
    cout << a[len - 1] << endl;
}

void insertionSort(int* a, int len){
    for (int i = 1; i < len; i ++){
        printarr(a, len);
        int v = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = v;
    }
}

int main(){
    int N, s;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i ++){
        cin >> s;
        a[i] = s;
    }
    insertionSort(a, N);
    printarr(a, N);
    return 0;
}
