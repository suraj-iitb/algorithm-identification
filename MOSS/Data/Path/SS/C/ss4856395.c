#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include<queue>
#include <sstream>
#include <set>
#include<stack>
#include <utility>
#define INF 1000000000000
const long long MOD = 998244353;

using namespace std;
typedef long long llong;

//int isalpha(char ch): ch がアルファベットなら true を返す
//int isdigit(char ch): ch が数字なら true を返す
//int islower(char ch): ch が小文字なら true を返す
//int isupper(char ch): ch が大文字なら true を返す
//int tolower(char ch): ch の小文字を返す
//int toupper(char ch): ch の大文字を返す

//string型
//size()	文字数を返す
//Insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//c_str()変換
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());
//map<type, type> dict;で宣言
//グラフ理論用変数
//vector<vector<llong> > graph(N);

//ソート
//降順sort(v.begin(), v.end(), std::greater<Type>());

//大文字から小文字へんかん
//w[i] = w[i]-'A'+'a';

//vector
//assignメソッド　引数：サイズ、値
//与えられたサイズと値でvectorを初期化する

//queueクラス
//find()次に取り出す値の表示をする。
//pop()値を取り出す。戻り値はなし
//push()キューに値をプッシュする

//priority_queueクラス

//切り上げ
//ceil
//floor

typedef struct _Edge{
    llong node;
    llong weight;
}Edge;

int main(){
    llong V,E,r;
    llong node;
    llong weight;
    cin >> V >> E >> r;
    vector<vector<pair<llong, llong> > > graph(V);
    vector<bool> visited(V, false);
    vector<llong> shortest_path(V, INF);
    priority_queue<pair<llong, llong> > PQ;
    pair<llong, llong> edge;
    llong s,t,d;
    for(int i=0; i<E; i++){
        cin >> s >> t >> d;
        edge.second = t;
        edge.first = d;
        graph[s].push_back(edge);
    }
    edge.second  = r;
    edge.first = 0;
    PQ.push(edge);
    shortest_path[r] = 0;
    visited[r]       = true;
    while(!PQ.empty()){
        edge = PQ.top();
        PQ.pop();
        node = edge.second;
        weight = edge.first;
        for(auto next_node_info:graph[node]){
            if(shortest_path[next_node_info.second]<(shortest_path[node]+next_node_info.first)){
                continue;
            }
            shortest_path[next_node_info.second] = shortest_path[node]+next_node_info.first;
            edge.first  = shortest_path[next_node_info.second]*-1;
            edge.second = next_node_info.second;
            PQ.push(edge);
        }
    }
    for(int i=0; i<shortest_path.size(); i++){
        if(shortest_path[i]==INF){
            cout << "INF" << endl;
            continue;
        }
        cout << shortest_path[i] << endl;
    }   
    return 0;
}

