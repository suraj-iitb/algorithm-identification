#include <bits/stdc++.h> /*ALDS1_2_B*/
using namespace std; 

int main(){

    int n,tem,minj,count; count = 0;

    cin >> n;
    vector<int> list(n);
    for(int i = 0; i < n; i++){
        cin >> list.at(i);
    }

    for(int i = 0; i < n;i++){
        minj = i;
        for(int j = i; j < n;j++){
            if(list.at(j) < list.at(minj)) 
            minj = j;
        }
        if(minj != i){
      		tem = list.at(i);
            list.at(i) = list.at(minj);
            list.at(minj) = tem;
            count++;
        }
        }
    for(int i = 0; n-1 > i; i++){
    cout << list.at(i) << ' ';
    }
    cout << list.at(n-1) <<endl;
  	cout << count << endl;
}

