#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N ; i++){
        int v =  A.at(i);
        int j = i -1;
        while(j >= 0 && A.at(j) > v){
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        for(int k = 0; k < N; k++){
            cout << A.at(k);
            if(k < N - 1) cout << " ";
            else cout << endl;
        }
    }
    
}
