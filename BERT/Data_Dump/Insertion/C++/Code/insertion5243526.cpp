#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

void vector_cout(vector<int> &a);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n){
        cin >> a[i];
    }

    vector_cout(a);
    
    FOR(i,1,n){
        int v=a[i];
        int j=i-1;
        while (j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        vector_cout(a);
    }
    return 0;
}
void vector_cout(vector<int> &a){
    FOR(i,0,a.size()){
        cout <<a[i];
        if(i<(a.size()-1)){
            cout<<" ";
        }
    }
    cout<<endl;
}
