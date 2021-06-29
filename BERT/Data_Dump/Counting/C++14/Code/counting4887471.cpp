#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void countingSort(vector<int> &array,int maxv){
    int n = array.size();
    vector<int> b_array(maxv+1,0),c_array(n+1,0);
    for(int i=0;i<n;i++){
        b_array.at(array.at(i))++;
    }

    for(int i=1;i<=maxv;i++){
        b_array.at(i) = b_array.at(i) + b_array.at(i-1);
    }

    for(int i=n-1;i>=0;i--){
        int num = array.at(i);
        int under_num = b_array.at(num);
        c_array.at(under_num) = num;
        b_array.at(num)--; 
    }

    for(int i=1;i<=n;i++){
        cout << c_array.at(i) ;
        if(i != n) cout << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    int maxv = array.at(0);
    for(int i=1;i<n;i++){
        if(maxv < array.at(i)) maxv = array.at(i);
    }
    countingSort(array,maxv);

}
