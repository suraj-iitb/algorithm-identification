#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    int count = 0;
    for(int i=0; i<n ; i++){
        cin >> array.at(i);
    }
    for(int i=0; i<n; i++){
        int minv = array.at(i);
        int minindex = i;
        for(int j=i; j<n; j++){
            if(minv > array.at(j)){
                minv = array.at(j);
                minindex = j;
            }
        }
        swap(array.at(i),array.at(minindex));
        if(array.at(i) != array.at(minindex)){
            count++;
        }
    }

    for(int i=0; i<n; i++){
        if(i != n-1){
            cout << array.at(i) << " ";
        }else{
            cout << array.at(i) << endl;
        }
        
    }
    cout << count << endl;
}
