#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    vector <int> row;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        row.push_back(temp);
    }
   
    for(int i=0;i<N ;i++){
        
        int k = i;
        for(int j=i - 1;j >= 0; j--){
            if(row[j] > row[k]){
                int temp = row[k];
                row[k] = row[j];
                row[j] = temp;
                k = j;
                
            }
        }
        for(int j=0;j<N;j++){
            if(j == N - 1){
                cout << row[j] << endl;
            }else{
                cout << row[j] << " ";
            }
        }
    }
    return 0;
}
