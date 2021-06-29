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

void bubbleSort(vector<int> a, int n){
    int flag = 1, count = 0;
    while(flag){
        flag = 0;
        for(int j=n-1; j>=1; j--){
            if(a[j]<a[j-1]){
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
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

    bubbleSort(a, n);
}
