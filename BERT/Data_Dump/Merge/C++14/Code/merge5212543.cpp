#include<bits/stdc++.h>
using namespace std;

 void merge(vector<int> &S,int left,int right,int &cnt){
    int mid=(right+left)/2;
    vector<int> L(mid-left+1),R(right-mid+1);
    for(int i=0;i<mid-left;i++){
        L.at(i)=S.at(left+i);
    }
    for(int i=mid;i<right;i++){
        R.at(i-mid)=S.at(i);
    }
    L.at(mid-left)=1000000001;
    R.at(right-mid)=1000000001;
    int i=0,j=0,k=left;
    while(k<right){
        if(L.at(i)<=R.at(j)){
            S.at(k)=L.at(i);
            i++; k++;
        }else{
            S.at(k)=R.at(j);
            j++; k++;
        }
        cnt++;
    }
    return;
}

 void mergeSort(vector<int> &S,int left,int right,int &cnt){
    if(left+1==right) return;
    int mid=(right+left)/2;
    mergeSort(S,left,mid,cnt);
    mergeSort(S,mid,right,cnt);
    merge(S,left,right,cnt);
    return;
}

void print(vector<int> S,int n){
    cout << S.at(0);
    for(int i=1;i<n;i++){
        cout << " " << S.at(i);
    }
    cout << endl;
}

int main(){
    int n,cnt=0;
    cin >> n;
    vector<int> S(n);
    for(int i=0;i<n;i++){
        cin >> S.at(i);
    }
    mergeSort(S,0,n,cnt);
    print(S,n);
    cout << cnt << endl;
    return 0;
}
