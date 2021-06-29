#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> row;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp = 0;
        cin >> temp;
        row.push_back(temp);
    }
    int times = 0;
    for(int i = 0;i<N;i++){
        int minj = i;
        for(int j = i;j < N;j++){
            if(row[j] < row[minj]){
                minj = j;
            }
        }
        if(i != minj){
            times ++;
            swap(row[i], row[minj]);
        }
        
    }
    
    for(int i = 0;i < N;i++){
        if(i == N - 1){
            cout << row[i] << endl;
        }else{
            cout << row[i] << " ";
        }
    }
    cout << times << endl;
    return 0;
}
