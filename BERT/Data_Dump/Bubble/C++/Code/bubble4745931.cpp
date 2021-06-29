#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A(100);

int bubble_Sort(int cnt){
    
    int sort_Already = 0;
    
    // 毎回、最後の位置からスタートして確認
    for(int i = N-1; i > sort_Already;){
        // 最後の位置からソート済まで入れ替えるか確認
        for(int j = i; j > sort_Already; j--){
            if(A[j] < A[j-1]){
            swap(A[j], A[j-1]);
            cnt++;
            }
        }
        sort_Already++;
    }
    
    return cnt;
}


int main(void){
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int count = 0;
    
    count = bubble_Sort(count);
    
    for(int i = 0; i < N; i++){
        cout << A[i] << (i != N-1 ? " " : "\n");
    }
    cout << count << endl;
    
}

