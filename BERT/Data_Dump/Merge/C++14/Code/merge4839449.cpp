#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt = 0;

void merge(int l,int mid,int r,vector<int> &array){
    vector<int> left_array,right_array;
    for(int i=l;i<mid;i++){
        left_array.push_back(array.at(i));
    }
    for(int i=mid;i<r;i++){
        right_array.push_back(array.at(i));
    }
    left_array.push_back(1000000001);
    right_array.push_back(1000000001);
    int lp=0,rp=0;
    for(int i=0;i<r-l;i++){
        cnt++;
        if(left_array.at(lp) < right_array.at(rp)){
            array.at(l+i) = left_array.at(lp);
            lp++;
        }else{
            array.at(l+i) = right_array.at(rp);
            rp++;
        }
    }
}

void mergeSort(vector<int> &array,int left,int right){
    if(left + 1 < right){
        int mid = ( left + right ) / 2;
        mergeSort(array,left,mid);
        mergeSort(array,mid,right);
        merge(left,mid,right,array);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i);
    }
    mergeSort(array,0,n);
    for(int i=0;i<n;i++){
        cout << array.at(i);
        if(i != n-1) cout<<" ";
    }
    cout << endl;
    cout << cnt << endl;
}
