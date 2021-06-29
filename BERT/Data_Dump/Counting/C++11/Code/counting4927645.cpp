#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void countingSort(vector<int> array,int n,int maxv){
    vector<int> b(maxv+1);
    vector<int> c(n+1);
    for(int i=0;i<n;i++){
        b.at(array.at(i))++;
    }
    
    for(int i=1;i<=maxv;i++){
        b.at(i) = b.at(i) + b.at(i-1);
    }
    
    for(int i=n;i>=1;i--){
        int num = array.at(i-1);
        int idx = b.at(num);
        //cout << idx << endl;
        c.at(idx) = num;
        b.at(num)--;
    }
    //cout << "finish!" << endl;
    for(int i=1;i<=n;i++){
        cout << c.at(i) ;
        if(i != n) cout << " ";
    }
}

int main(){
    int n;
    int maxv = -1;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i);
        if(maxv < array.at(i)) maxv = array.at(i);
    }
    countingSort(array,n,maxv);
    cout << endl;
}
