#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                count++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}


int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bubbleSort(a, n);

    return 0;
}


