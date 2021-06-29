#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <cmath>

#define Max(a,b) (a <= b)?b:a                   //大きい方を返す
#define Rep(i, n) for(int i = 0; i < n; i++)    //i=0 → i=nまでループ
#define Repr(i,n) for(int i = n; i <=0; i--)    //i=n → i=0までループ　
#define For(i, m, n) for(int i = m;i < n;i++)   //i=m → i=nまでループ
#define All(x) (x).begin(),().end()             //xの最初と最後のイテレータを返す 
#define Out(n) cout << n << endl


using namespace std;



int main(){
    vector<int> data;
    int n; cin >> n;

    int inp;
    Rep(i,n){
        cin >> inp;
        data.push_back(inp);
    }

    int v,j;
    Rep(i,data.size()){
        v = data[i];
        j = i - 1;
        while((j >= 0) && data[j] > v){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = v;

        Rep(i,data.size()){
            if(i == data.size() - 1){
                Out(data[i]);
            } else {
            cout << data[i] << ' ';
            }
            
        }

    }
}
