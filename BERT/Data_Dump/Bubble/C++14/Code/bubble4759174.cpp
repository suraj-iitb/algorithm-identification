#include<iostream>
#include<vector>

using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void show(vector<int> vec){
    int cnt = 0;
    for(auto a: vec){
        cout << a;
        if(cnt!= vec.size()-1) cout << " ";
        else cout << endl;
        cnt++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i < n;i++){
        cin >> A.at(i);
    }
    int cnt = 0;
    for(int i=1;i < A.size();i++){
        for(int j=1;j < A.size();j++){
            if(A.at(j) < A.at(j-1)) {
                swap(A.at(j),A.at(j-1));
                cnt++;
            }
        }
    }
    show(A);cout << cnt << endl;
    return 0;
}
