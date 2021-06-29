#include <bits/stdc++.h>
using namespace std;

void print(vector<int> A,int N){
    for(int i=0;i<N-1;i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
}

void insertionSort(vector<int> A,int N){
    print(A,N);
    for(int i=1;i<N;i++){
        int v=A.at(i);
        int j=i-1;
        while(j>=0 && v<A.at(j)){
            A.at(j+1)=A.at(j);
            j--;
        }
        A.at(j+1)=v;
        print(A,N);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    insertionSort(A,N);
	return 0;
}
