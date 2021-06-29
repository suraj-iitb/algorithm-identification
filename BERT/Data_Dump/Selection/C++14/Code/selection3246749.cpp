#include <bits/stdc++.h>

#define ll long long int
#define INFTY (1<<21)

using namespace std;

void printVector(vector<int> A, int N){
    for(int i = 0; i < N-1; i++)
        cout<<A[i]<<" ";
    cout<<A[N-1]<<endl;
}

void swap(int& a, int& b){
    int tmp = b;
    b = a;
    a = tmp;
}

void selectionSort(vector<int>& A, int N){
    int c = 0;
    for(int i = 0; i < N-1; i++){
        int minNumIdx = i;
        for(int j = i+1; j < N; j++)
            if(A[j]<A[minNumIdx])
                minNumIdx = j;
        if(i != minNumIdx){
            swap(A[i], A[minNumIdx]);
            c++;
        }
    }
    printVector(A, N);
    cout<<c<<endl;
}

int main(void){
    cin.sync_with_stdio(false);
    int N; cin>>N;
    vector<int> nums;
    for(int i = 0; i < N; i++){
        int tmp; cin>>tmp;
        nums.push_back(tmp);
    }

    selectionSort(nums, N);

    return 0;
}
