#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

void printArray(){
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}

void insertionSort(){
    int v,j;
    printArray();
    for(int i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printArray();
    }
}

void bubbleSort(){
    int cnt = 0;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
                flag = 1;
                cnt++;
            }
        }
    }
    printArray();
    cout << cnt << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    //insertionSort();
    bubbleSort();

    return 0;
}
