#include<iostream>  //bubbleSort
#include<utility>
using namespace std;
int main(){
    int n,A[101],j;  //nは要素の長さ
    int flag = 1;
    int i = 0;  //未ソート部分列の先頭インデックス
    int count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){  //A[]に値を入れる
        cin >> A[i];
        //cout << A[i] << " ";
    }
    
    
    
    while (flag != 0){
        flag = 0;
        for(j = n-1; j > i ;j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                count++;
                
            }
            
        }
        
        //for(int k = 0; k < n; k++){
        //    cout << A[k] << " ";
        //}
        
        //cout << endl;
        
        i++;
    }
    
    
    
    
    for(int k = 0; k < n; k++){  // 表示
        //cout << A[k];
        if(k == n-1) cout << A[k];
        else cout << A[k] << " ";
        
    }
    
    cout << endl;
    cout << count << endl;   //回数の表示
    
    return 0;
}

