#include <bits/stdc++.h>
using namespace std;

void print(vector<int> A,int N){
    for(int i=0;i<N-1;i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
}

void selectionSort(vector<int> A,int N){
    int count=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A.at(j)<A.at(minj)){
                minj=j;
            }
        }
        if(minj!=i){
            swap(A.at(i),A.at(minj));
            count++;
        }
    }
    print(A,N);
    cout << count << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    selectionSort(A,N);
	return 0;
}

