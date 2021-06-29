#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
#define LLLLLLL 1000000001

void merge(vector <int> & A, int left, int right, int mid,int &count){
    vector<int> L;
    vector<int> R;
    rep(i,mid-left){
        L.emplace_back(A.at(i+left));
    }
    for(int i=mid;i<right;++i){
        R.emplace_back(A.at(i));
    }
    int n1=L.size();
    int n2=R.size();
    L.emplace_back(LLLLLLL);
    R.emplace_back(LLLLLLL);
    auto itr_l=L.begin();
    auto itr_r=R.begin();
    rep(i,n1+n2){
        if(*itr_l>*itr_r){
            A.at(i+left)=*itr_r;
            advance(itr_r,1);
            ++count;
        }else{
            A.at(i+left)=*itr_l;
            advance(itr_l,1);
            ++count;
        }
    }
    
}

void mergeSort(vector <int> & A, int left, int right,int &count){
    if(left+1<right){
        int mid=(right+left)/2;
        mergeSort(A,left,mid,count);
        mergeSort(A,mid,right,count);
        merge(A,left,right,mid,count);
    }else{

    }
}



int main(){
    int n;
    cin>>n;
    int count=0;
    vector<int> A(n);
    rep(i,n){
        cin>>A.at(i);
    }
    mergeSort(A,0,n,count);
    cout<<A.at(0);
    for(int i=1;i<A.size();++i){
        cout<<' '<<A.at(i);
    }
    cout<<endl;
    cout<<count<<endl;

}
