#include<bits/stdc++.h>
using namespace std;

//昇順に並べる挿入ソート
void insertionSort(vector<int> a, int n){
    for(int k=0; k<n; k++){
        cout << a[k];
        if(k!=n-1){
            cout << " ";
        }
    }
    cout << endl;
    
    int v, j;
    for(int i=1; i<n; i++){
        v = a[i];
        j = i-1;
        while(j>=0 && a.at(j)>v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
        for(int k=0; k<n; k++){
            cout << a[k];
            if(k!=n-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    insertionSort(a,n);

}
