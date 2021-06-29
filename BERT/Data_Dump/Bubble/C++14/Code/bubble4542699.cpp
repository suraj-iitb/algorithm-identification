#include <bits/stdc++.h> /*ALDS1_2_A*/
using namespace std; 

int main(){
    int n,tem,count; count = 0;
    bool flag; flag = true;

    cin >> n;
    vector<int> list(n);
    for(int i = 0; i < n; i++){
        cin >> list.at(i);
    }

    while(flag){
        flag = false;
        for(int i = 0; i < n-1; i++){
            if(list.at(i) > list.at(i+1)){
                tem = list.at(i);
                list.at(i) = list.at(i+1);
                list.at(i+1) = tem;
                flag = true;
                count++;
            }
        }
    }
    for(int i = 0; n-1 > i; i++){
        cout << list.at(i) << ' ';
    }
    cout << list.at(n-1) <<endl;
  	cout << count << endl;
}

