#include<bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>& arr, int n){
    int cnt = 0;
    for (int i=0; i<n-1; ++i){
        int minj = i;
        for (int j=i+1; j<n; ++j){
            if(arr[j] < arr[minj])
                minj = j;
        }
        if(minj != i){
            swap(arr[minj], arr[i]);
            cnt++;
        }
    }
    for (int i=0; i<n; ++i){
        if(i>0) cout<<" ";
        cout<<arr[i];
    }
    cout<<endl;
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (auto&v:arr)
        cin>>v;
    cout<< selectionSort(arr, n)<<endl;
    return 0;
}
