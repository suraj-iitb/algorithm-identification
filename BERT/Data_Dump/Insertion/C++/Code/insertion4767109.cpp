//挿入アルゴリズム
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>A(n);
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    //とりあえず表示
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i!=n-1){
                cout << " ";
            }else{
                cout << "\n";
            }
    }

    //ソート開始
    for(int i = 1; i < n; i++){
        int j = i;
        while(j >= 1){
            if(A[j]<=A[j-1]){
                int tmp;
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                j--;
            }else{
                j--;
            } 
        }
        for(int k = 0; k < n; k++){
            cout << A[k];
            if(k!=n-1){
                cout << " ";
            }else{
                cout << "\n";
            }
        }
    }
}
