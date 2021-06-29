#include <bits/stdc++.h>
using namespace std;

void Selectionsort(vector<int> A){
    int count=0;
    int N=A.size();
    for(int i=0;i<N-1;i++){
        int min=i;
        for(int j=i+1;j<N;j++){
            if(A.at(j)<A.at(min)){
                min=j;
            }
        }
        swap(A.at(i),A.at(min));
        if(i!=min) count++;
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
    Selectionsort(A);
}
