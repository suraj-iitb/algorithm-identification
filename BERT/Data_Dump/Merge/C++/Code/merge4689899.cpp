#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int compare_cnt = 0;

void merge(vector<int> &s, int left, int mid, int right){
    vector<int> n1(mid - left);
    vector<int> n2(right - mid);

    rep(i, mid - left){
        n1.at(i) = s.at(left + i);
    }
    rep(i, right - mid){
        n2.at(i) = s.at(mid + i);
    }
    n1.push_back(INT_MAX);
    n2.push_back(INT_MAX);

    int n1_index = 0;
    int n2_index = 0;

    // cout << "left mid right " << left << " " << mid << " " << right << endl;
    for(int i = left; i < right; i++){
        if(n1.at(n1_index) > n2.at(n2_index)){
            s.at(i) = n2.at(n2_index);
            n2_index++;
        }else{
            s.at(i) = n1.at(n1_index);
            n1_index++;
        }
        compare_cnt++;
    }
}

void mergeSort(vector<int> &s, int left, int right){
    if(left + 1 < right){
        int mid = (right + left) / 2;
        mergeSort(s, left, mid);
        mergeSort(s, mid, right);
        merge(s, left, mid, right);
    }

}

void printVec(vector<int> s){
    rep(i, s.size()-1){
        cout << s.at(i) << " ";
    }
    cout << s.at(s.size()-1) << endl;
}

int main(){
    int n; cin >> n;
    vector<int> s(n);
    rep(i, n){
        cin >> s.at(i);
    }

    int left = 0;
    int right = s.size();
    mergeSort(s, left, right);

    printVec(s);
    cout << compare_cnt << endl;
}
