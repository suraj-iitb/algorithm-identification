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

void bubbleSort(vector<int>& A, int N){
    bool bEnd = true;
    int c=0;
    while(bEnd){
        bEnd = false;
        for(int i = 0; i < N-1; i++){
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                bEnd = true;
                c++;
            }
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

    bubbleSort(nums, N);

    return 0;
}
