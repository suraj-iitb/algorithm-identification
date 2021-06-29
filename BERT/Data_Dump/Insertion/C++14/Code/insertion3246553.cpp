#include <bits/stdc++.h>

#define ll long long int
#define INFTY (1<<21)

using namespace std;

void printVector(vector<int> A, int N){
    for(int i = 0; i < N-1; i++)
        cout<<A[i]<<" ";
    cout<<A[N-1]<<endl;
}

void insertionSort(vector<int>& A, int N){
    for(int i = 0; i < N; i++){
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printVector(A, N);
    }
}

int main(void){
    cin.sync_with_stdio(false);
    int N; cin>>N;
    vector<int> nums;
    for(int i = 0; i < N; i++){
        int tmp; cin>>tmp;
        nums.push_back(tmp);
    }

    insertionSort(nums, N);

    return 0;
}
