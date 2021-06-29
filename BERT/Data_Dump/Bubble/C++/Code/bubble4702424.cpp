#include <bits/stdc++.h>
using namespace std;

int bubblesort(vector<int> &A,int N){
    int sw=0;
    bool flag=1;
    while(flag){
        for(int i=0;flag;i++){
            flag=0;
            for(int j=N-1;j>=1;j--){
                if(A.at(j)<A.at(j-1)){
                    swap(A.at(j),A.at(j-1));
                    flag=1;
                    sw++;
                } 
            }
        }
    }
    return sw;
}

int main(void){
    int N;
    cin >> N;
    
vector<int> A(100);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    
    int sw=bubblesort(A,N);
    
    for(int i=0;i<N-1;i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
    
    cout << sw << endl;
    return 0;
}
