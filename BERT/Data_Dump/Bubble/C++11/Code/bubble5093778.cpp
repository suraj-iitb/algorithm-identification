#include<bits/stdc++.h>
using namespace std;


const int N = 100;

int R[N];

int BubbleSort(int arr[], int n){
    int cnt = 0;
    int flag = 1;
    for (int i=0; flag; i++){
        flag = 0;
        for (int j=1; j<n-i; j++){
            if(arr[j] < arr[j-1]){
                flag = 1;
                swap(arr[j], arr[j-1]);
                cnt++;
            }
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
    for (int i=0; i<n; ++i)
        cin>>R[i];
    cout<<BubbleSort(R, n)<<endl;
    return 0;    
}
