#include <bits/stdc++.h>
using namespace std;

void Bubblesort(vector<int> A){
    int count=0;
    for(int i=0;i<A.size()-1;i++){
        for(int j=A.size()-1;j>=i+1;j--){
            if(A.at(j)<A.at(j-1)){
                swap(A.at(j),A.at(j-1));
                count++;
            }
        }
    }
    for(int i=0;i<A.size();i++){
        if(i) cout << " ";
        cout << A.at(i);
    }
    cout << endl;
    cout << count << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    Bubblesort(A);
}
