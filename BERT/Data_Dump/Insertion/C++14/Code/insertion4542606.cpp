#include <bits/stdc++.h> /*ALDS1_1_A*/
using namespace std; 

int main(){

    int n,tem,x;
    cin >> n;
    vector<int> sort(n);
    for(int i = 0; i< n; i++){
        cin >> sort.at(i);
    }
    for (int z = 0; z < n-1; z++){
        cout << sort.at(z) << ' ';
    }
    cout << sort.at(n-1) <<endl;

    for(int i = 1; i < n; i++){
        tem = sort.at(i);
        x = i-1;
        while(x >= 0 && sort.at(x) >= tem){
            sort.at(x+1) = sort.at(x);
            x--;
        }
        sort.at(x+1) = tem;
        
        for (int z = 0; z < n-1; z++){
            cout << sort.at(z) << ' ';
        }
        cout << sort.at(n-1) <<endl;
    }
}
