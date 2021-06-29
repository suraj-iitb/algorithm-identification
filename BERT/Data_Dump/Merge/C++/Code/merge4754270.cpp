#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <algorithm>
#define INF 100000000000000
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
//insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());

//グラフ理論用変数
//vector<vector<llong> > graph(N);
llong ans=0;
void merge(llong left, llong right, llong *A, llong n){
    llong mid = (left+right)/2;

    //要素数が一個
    if(right==left){
        return;
    }
    merge(left, mid, A, n);
    merge(mid+1, right, A, n);
    llong LeftArrayIndex=left;
    llong RightArrayIndex=mid+1;
    llong CopyArray[n];
    for(int i=left; i<=right; i++){
        CopyArray[i] = A[i];
    }
    for(llong i=left; i<=right; i++){
        if(RightArrayIndex>right){
            A[i] = CopyArray[LeftArrayIndex];
            LeftArrayIndex++;
            ans++;
        }else if(LeftArrayIndex>mid){
            A[i] = CopyArray[RightArrayIndex];
            RightArrayIndex++;
            ans++;
        }
        else if(CopyArray[LeftArrayIndex] >= CopyArray[RightArrayIndex]){
            A[i] = CopyArray[RightArrayIndex];
            RightArrayIndex++;
            ans++;
        }else{
            A[i] = CopyArray[LeftArrayIndex];
            LeftArrayIndex++;
            ans++;
        }
    }
    return;
}

int main(){
    llong n;
    cin >> n;
    llong A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    merge(0, n-1, A, n);
    for(int i=0; i<(n-1); i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << ans << endl;
}
