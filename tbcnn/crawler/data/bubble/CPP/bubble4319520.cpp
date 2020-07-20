#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,num,tmp,flag = 1,count = 0;
    cin >> n;
    
    vector<int> num_box;
    for(int i = 0; i < n; i++){
        cin >> num;
        num_box.push_back(num);
    }
    
    while(flag){
        flag = 0;
        for(int i = n -1; i > 0; i--){
            if(num_box[i] < num_box[i - 1]){
                tmp = num_box[i];
                num_box[i] = num_box[i - 1];
                num_box[i - 1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    cout << num_box[0];
    for(int i = 1; i < n; i++){
        cout <<' ' << num_box[i];
    }
    cout << endl << count << endl;
    
    return 0;
}
