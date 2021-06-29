# include <bits/stdc++.h>
using namespace std;

int main(){
    int num_value, i, j, value_stacked;
    cin >> num_value;
    vector<int> values(num_value);
    for(i=0;i<num_value;i++){
        cin >> values.at(i);
    }
    
    // 数列初期値の出力
    for(i=0;i<num_value-1;i++){
        cout << values.at(i) << " ";
    }
    cout << values.at(num_value-1) << endl;
    
    // 挿入ソート開始
    for(i=1; i<num_value; i++){
        value_stacked = values.at(i);
        j = i-1;
        
        while(j>=0 && values.at(j)>value_stacked){
            values.at(j+1) = values.at(j);
            j--;
        }
        values.at(j+1) = value_stacked;
        
        for(j=0;j<num_value-1;j++){
            cout << values.at(j) << " ";
        }
        cout << values.at(j) << endl;
    }
    
    return 0;
}
