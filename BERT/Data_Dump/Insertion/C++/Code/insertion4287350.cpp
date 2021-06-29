#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, in;
    vector <int> val;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> in;
        val.push_back(in);
        if(i != n - 1){
            cout << in << " ";
        }else{
            cout << in << endl;
        }
    }
    for(int i = 1; i < n; i++){
        int v = val[i];
        int j = i - 1;
        while(j >= 0 && val[j] > v){
            val[j + 1] = val[j];
            j--;
        }
        val[j + 1] = v;

        for(int k = 0; k < n; k++){
            if(k != n - 1){
                cout << val[k] << " " ;
            }else{
                cout << val[k] << endl;
            }
        }
    }

    return 0;
}
