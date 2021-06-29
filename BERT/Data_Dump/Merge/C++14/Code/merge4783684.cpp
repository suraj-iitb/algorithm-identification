#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int cnt;

void marge(vector<int> &vec,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+5,INT_MAX),R(n2+5,INT_MAX);
    for(int i=0;i < n1;i++) L.at(i) = vec.at(left+i);
    for(int i=0;i < n2;i++) R.at(i) = vec.at(mid+i);
    int i = 0,j = 0;
    
    for(int k = left;k < right;k++){
        if(L.at(i) <= R.at(j)){
            vec.at(k) = L.at(i);
            i++;
            cnt++;
        }else{
            vec.at(k) = R.at(j);
            j++;
            cnt++;
        }
    }
}

void margesort(vector<int> &vec,int left,int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        margesort(vec,left,mid);
        margesort(vec,mid,right);
        marge(vec,left,mid,right);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> S(n);
    for(int i=0;i < S.size();i++) cin >> S.at(i);
    margesort(S,0,S.size());
    for(int i=0;i < S.size();i++){
        cout << S.at(i);
        if(i != S.size()-1) cout << " ";
        else cout << endl;
    }
    cout << cnt << endl;
    return 0;
}
