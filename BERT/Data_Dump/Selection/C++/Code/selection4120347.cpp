#include<bits/stdc++.h>
using namespace std;

void printvec(vector<int> a, int n){
    for(int i=0; i<n; i++){
        cout << a[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
}

void selectionSort(vector<int> a, int n){
    int count = 0;
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            count++;
        }
    }
    printvec(a, n);
    cout << count << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    selectionSort(a, n);
}
