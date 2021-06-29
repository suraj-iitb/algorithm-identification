#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<int>& a){
    int n = a.size();
    for(int i=1; i<n; i++){
        int j = i;
        while(j>=1 && a[j-1]>a[j]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
        for(int k=0; k<n-1; k++){
            cout << a[k] << " ";
        }
        cout << a[n-1] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1] << endl;
    InsertionSort(a);
    return 0;
}
