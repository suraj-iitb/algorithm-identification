#include<iostream>
#include<vector>
using namespace std;

void OutputVec(vector<int> A){
    for(int i=0;i<A.size();i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void InsertionSort(vector<int>& A,int n){
    for(int i=1;i<n;i++){
        int v = A[i];
        int j = i - 1;
        while(j>=0&&A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        OutputVec(A);
    }
}

int main(){
    int N = 0;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    OutputVec(A);
    InsertionSort(A,N);
}
