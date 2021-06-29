#include <bits/stdc++.h>
using namespace std;

void print(vector<int> A,int N){
    for(int i=0;i<N-1;i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
}

void bubbleSort(vector<int> A,int N){
    int flag=1,count=0,i=0;
    while(flag){
        flag=0;
        for(int j=N-1;j>i;j--){
            if(A.at(j)<A.at(j-1)){
                swap(A.at(j),A.at(j-1));
                flag=1;
                count++;
            }
        }
        i++;
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
    bubbleSort(A,N);
	return 0;
}
