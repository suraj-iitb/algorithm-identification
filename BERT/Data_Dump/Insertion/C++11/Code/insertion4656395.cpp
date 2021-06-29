#include<bits/stdc++.h>
using namespace std; 

void insertsort(vector<int> &array,int n){
    for(int i=1; i<n; i++){
        int val = array.at(i);
        int j = i-1;
        while(j >= 0 && array.at(j) > val){
            array.at(j+1) = array.at(j);
            j--;
        }
        array.at(j+1) = val;
        for(int k=0; k<n; k++){
        if(k == n-1){
            cout << array.at(k) << "\n";
        }else{
            cout << array.at(k) << " ";
        }
    }
}
}

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++) cin >> array.at(i);
    for(int k=0; k<n; k++){
        if(k == n-1){
            cout << array.at(k) << "\n";
        }else{
            cout << array.at(k) << " ";
        }
    }
    insertsort(array,n);
}
