#include<iostream>
#include<vector>
using namespace std;

struct P{
    char z;
    int y;
};

void merge(vector<P> &a,int b,int mid,int c){
    int k=mid-b;
    int t=c-mid;
    vector<P> d(k+1);
    vector<P> e(t+1);
    for(int i=0;i<k;i++){
        d[i]=a[b+i];
        
    }
    for(int i=0;i<t;i++){
        e[i]=a[mid+i];
    }
    d[k].y=e[t].y=2000000000;
    int j=0,u=0;
    for(int i=b;i<c;i++){
        if(d[j].y<=e[u].y){
            a[i]=d[j];
            j++;
        }
        else {
            a[i]=e[u];
            u++;
        }
    }
    
    
}

void mergesort(vector<P> &a,int b,int c){
    if(b+1<c){
        int mid=(b+c)/2;
        mergesort(a,b,mid);
        mergesort(a,mid,c);
        merge(a,b,mid,c);
    }
}

int solve(vector<P> &a,int b,int c){
    int x=a[c].y;
    int i=b-1;
    for(int j=b;j<c;j++){
        if(a[j].y<=x){
            i++;
            swap(a[i],a[j]);
        }
        
    }
    swap(a[i+1],a[c]);
    return i+1;
}

void quicksort(vector<P> &a,int b,int c){
    if(b<c){
        int k=solve(a,b,c);
        quicksort(a,b,k-1);
        quicksort(a,k+1,c);
    }
}

int main(){
    int n;
    cin>>n;
    vector<P> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].z>>a[i].y;
    }
    vector<P> v=a;
    quicksort(a,0,n-1);
    mergesort(v,0,n);
    bool w=true;
    for(int i=0;i<n;i++){
        if(a[i].z!=v[i].z){
            w=false;
            break;
        }
    }
    if(w)cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    for(P f:a){
        cout<<f.z<<' '<<f.y<<endl;
    }
}
