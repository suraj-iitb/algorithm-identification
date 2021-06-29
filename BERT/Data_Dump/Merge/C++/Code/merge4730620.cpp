#include <bits/stdc++.h>
using namespace std;

void show_array(vector<int> &arr){
    for(int i=0; i<arr.size() ; i++) cout << arr.at(i) << " ";
    cout << endl ;
}

void merge(vector<int> &arr,int left,int mid,int right,int &count){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> left_array(n1);
    vector<int> right_array(n2);
    for(int i=0; i<n1; i++){
        //cout << left + i << endl;
        left_array.at(i) = arr.at(left + i);
    }
    for(int i=0; i<n2; i++){
        //cout << right + i << endl;
        right_array.at(i) = arr.at(mid + i);
    }
    int i=0, j=0;
    left_array.push_back(2147483647);
    right_array.push_back(2147483647);
    for(int k=left; k<right; k++){
        count++;
        if (left_array.at(i) <= right_array.at(j)){
            arr.at(k) = left_array.at(i);
            i++;
        }else{
            arr.at(k) = right_array.at(j);
            j++;
        }
    }
}

void merge_sort(vector<int> &arr, int left, int right,int &count){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        merge_sort(arr,left,mid,count);
        merge_sort(arr,mid,right,count);
        merge(arr,left,mid,right,count);
        //show_array(arr);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++) cin >> array.at(i);
    int count=0;
    merge_sort(array,0,n,count);
    for(int i=0; i<n; i++) {
        if(i != n-1){
            cout << array.at(i) << " ";
        }else{
            cout << array.at(i);
        }
    }
        
    cout << endl << count << endl;
}
