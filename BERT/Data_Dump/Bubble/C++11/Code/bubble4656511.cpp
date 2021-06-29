#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &array,int n,int &count){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<n-1; i++){
            if(array.at(i) > array.at(i+1)){
                swap(array.at(i),array.at(i+1));
                count ++;
                flag = true;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++){
        cin >> array.at(i);
    }
    int count = 0;
    bubble(array,n,count);
    for(int i=0; i<n ; i++){
        if(i == n-1){
            cout << array.at(i) << endl;
        } else {
            cout << array.at(i) << " ";
        }
    }
    cout << count << endl;
    
}
