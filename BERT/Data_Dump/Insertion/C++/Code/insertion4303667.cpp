//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

// vector 操作  vector<int> data(10,5) 5が10個　data(10) 要素数10
// v.size(), v.empty(), v.insert(itr,値), v.erase(itr) (first,last),
// sort(itr), find(all(x),値),reverse(itr),accumulate(itr,0) 積算,
//v.swap
// stringも同じ itrがただの数字になる
// s.substr(n,m)n番目以降m文字取り出す　erase(n,m)も  s.find
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

// map 操作  map<string,int> mp キー=string 値=int型  pair< , >型
// 代入:mp["abc"]=123  mp.erase(キー)
// itr = mp.begin()のとき　itr->first = key, itr->second = val
// mp.find(key) itrを返す
typedef pair<int,int> P;  //q(p.first,p.second)で定義できる？

// lcm( , ) gcd( , ) 最大公約数　最小公倍数
//if(cin.eof()) break; 入力数が決まってないとき
//ifstream  whilwee(ifs>>data)

// 浮動小数点
// cout << fixed; 以下と組fみ合わせで小数点以下n桁
// cout << setprecision(n) << 値; n桁表記
// defaultfloat
int main (){
    int n;
    cin >> n;
    vei a(n);
    REP(i,n){
        cin >> a[i];
    }
    REP(i,n-1){
            cout << a[i] << " ";
    }
    cout << a[n-1];
    cout << '\n';

    for(int i=1;i<n;i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
            a[j+1]=v;
        }
        REP(i,n-1){
            cout << a[i] << " ";
        }
        cout << a[n-1];
        cout << '\n';
    }
}
