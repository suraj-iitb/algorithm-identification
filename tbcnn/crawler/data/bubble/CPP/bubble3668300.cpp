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
    bool flag = true;
    while(flag){
        flag = false;
        for(int j = N - 1 ; j > 0; j--){
            if(row[j] < row[j - 1]){
                swap(row[j ],row[j - 1]);
                times ++;
                flag = true;
            }
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
