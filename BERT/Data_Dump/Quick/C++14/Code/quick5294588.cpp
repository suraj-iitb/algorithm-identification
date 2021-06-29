#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
#define LLLLLLL 1000000001

void merge(vector<char> &Pat,vector <int> & A, int left, int right, int mid,int &count){
    vector<int> L;
    vector<int> R;
    vector<char> Lp;
    vector<char> Rp;
    rep(i,mid-left){
        L.emplace_back(A.at(i+left));
        Lp.emplace_back(Pat.at(i+left));
    }
    for(int i=mid;i<right;++i){
        R.emplace_back(A.at(i));
        Rp.emplace_back(Pat.at(i));
    }
    int n1=L.size();
    int n2=R.size();
    L.emplace_back(LLLLLLL);
    R.emplace_back(LLLLLLL);
    auto itr_l=L.begin();
    auto itr_pl=Lp.begin();
    auto itr_r=R.begin();
    auto itr_pr=Rp.begin();
    rep(i,n1+n2){
        if(*itr_l>*itr_r){
            A.at(i+left)=*itr_r;
            Pat.at(i+left)=*itr_pr;
            advance(itr_r,1);
            advance(itr_pr,1);
            ++count;
        }else{
            A.at(i+left)=*itr_l;
            Pat.at(i+left)=*itr_pl;
            advance(itr_l,1);
            advance(itr_pl,1);
            ++count;
        }
    }
    
}

void mergeSort(vector<char> &Pat,vector <int> & A, int left, int right,int &count){
    if(left+1<right){
        int mid=(right+left)/2;
        mergeSort(Pat,A,left,mid,count);
        mergeSort(Pat,A,mid,right,count);
        merge(Pat,A,left,right,mid,count);
    }else{

    }
}




void bubbleSort(vector<char> &Pata, vector <int> &A){
    for(int i=0;i<A.size();++i){
        bool flag=true;
        for(int j=A.size()-1;j>i;--j){
            if(A.at(j)<A.at(j-1)){
                int ch=A.at(j);
                char pat=Pata.at(j);
                A.at(j)=A.at(j-1);
                A.at(j-1)=ch;
                Pata.at(j)=Pata.at(j-1);
                Pata.at(j-1)=pat;
                flag=false;
            }
        }
        if(flag){
            break;
        }
    }
}




int partition(vector<char> &Pata, vector <int> &A, int p,int r){
    int x=A.at(r);
    int i =p-1;
    int j=p;
    while(j<r+1){
        if(A.at(j)<=x){
            int ch=A.at(i+1);
            char pat=Pata.at(i+1);
            A.at(i+1)=A.at(j);
            A.at(j)=ch;
            Pata.at(i+1)=Pata.at(j);
            Pata.at(j)=pat;
            i++;
            j++;
            
        }else{
            ++j;
        }
    }
    //A.at(r)=A.at(i);
    //A.at(i)=x;
    return i;
}

void quicksort(vector <char> &Pata, vector <int> &A, int p,int r){
    int q;
    if(p<r){
        q=partition(Pata,A,p,r);
        quicksort(Pata,A,p,q-1);
        quicksort(Pata,A,q+1,r);
    }

}

int main(){
    int n;
    cin>>n;
    
    vector <int> A(n);
    vector <char> Pata(n);
    rep(i,n){
        cin>>Pata.at(i);
        cin>>A.at(i);
    }
    int count=0;
    vector <int> A2(n);
    copy(A.begin(),A.end(),A2.begin());
    vector <char> Pata2(n);
    copy(Pata.begin(),Pata.end(),Pata2.begin());
    
    quicksort(Pata,A,0,A.size()-1);
    int a=partition(Pata,A,0,A.size()-1);
    
    mergeSort(Pata2,A2,0,n,count);
    
    if(Pata==Pata2){
        cout<<"Stable"<<endl;
    }else{
        cout<<"Not stable"<<endl;
    }
    
    for(int i=0;i<n;++i){
        cout<<Pata.at(i)<<' '<<A.at(i)<<endl;
        //cout<<A.at(i)<<endl;
    }
    
    
    
    

}
