#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(to); x++) // for簡略表記
#define DUMP(ar) for(unsigned int i=0; i<ar.size(); i++) cout << "[" << i << "]:" << ar[i] << endl // 配列一覧表示
#define DUMPL(ar) for(unsigned int i=0; i<ar.size(); i++) { cout << ar[i]; if(i<ar.size()-1) cout << ' '; } cout << endl; // 配列一行一覧表示"
#define COUT(x) cout << x << endl // 単要素出力
#define ALL(ar) ar.begin(), ar.end() // コンテナの全要素
#define LOOPD(i) cout << "ループ[" << i << "]回目---------------" << endl // ループ回数デバグ
using namespace std;
// cout << fixed << setprecision(4) で小数点以下4桁の桁そろえ
// cout << setw(5) << ... で表示形式を5桁に設定 5桁未満なら頭に空白がつく 5桁越なら先頭から5桁まで
// cout << setw(5) << setfill('0') << ... で空白部分の埋め文字に5を使う
// goto ANSWER; で最後へ飛ぶ
// getline(cin, [変数]); で空白などを含む入力の受け取り(行ごとの受け取り)
// cin >> ws; でそこまでにストリームに残されたホワイトスペースを取り除く(=以降のgetlineの有効化)

int merge(vector<int> &a){
    static int count = 0;
    int left = a.size() / 2;
    vector<int> a_left;
    vector<int> a_right;
    // 分割
    for(int i=0; i<(int)a.size(); i++){
        if(i < left){
            a_left.push_back(a.at(i));
        }else{
            a_right.push_back(a.at(i));
        }
    }
    // ソート
    if(a.size() > 2){
        merge(a_left);
        merge(a_right);
    }
    if(a.size() == 1){ // 3つの配列を分割した際起こり得る
        if(a_left.size() == 1) a = a_left;
        else a = a_right;
        return 0;
    }
    // 結合
    int lc = 0, rc = 0;
    // cout << "[left.size: " << a_left.size() << " right.size: " << a_right.size() << "]" << endl;
    for(int i=0; i<(int)a.size(); i++){
        // cout << '\t' << "lc: " << lc << " rc: " << rc << endl;
        count++;
        if(lc >= left) { a.at(i) = a_right.at(rc++); continue; }
        if(rc >= (int)a_right.size()) { a.at(i) = a_left.at(lc++); continue; }

        if(a_left.at(lc) <= a_right.at(rc)){
            a.at(i) = a_left.at(lc++);
        }else{
            a.at(i) = a_right.at(rc++);
        }
    }
    return count;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    /*
    6 3 5 1 8 2 4 7
    6 3 5 1  -  8 2 4 7
    6 3  -  5 1  -  8 2  -  4 7
    3 6  -  1 5  -  2 8  -  4 7
    1 3 5 6  -  2 4 7 8
    1 2 3 4 5 6 7 8
    */

    int n;
    cin >> n;
    vector<int> s(n);
    FOR(i, n) cin >> s[i];
    // s = {6, 3, 5, 1, 8, 2, 4, 7};

    int ans = merge(s);

    DUMPL(s);
    COUT(ans);

ANSWER:
    return 0;
}
