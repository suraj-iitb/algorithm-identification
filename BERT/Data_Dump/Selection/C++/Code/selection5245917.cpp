#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
int selection_sort(vector<int> &a);
void vector_cout(vector<int> &a);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n){
        cin >> a[i];
    }
    int count;
    count=selection_sort(a);
    vector_cout(a);
    cout<<count<<endl;
    return 0;
}

void vector_cout(vector<int> &a){
    FOR(i,0,a.size()){
        cout <<a[i];
        if(i<(a.size()-1)){
            cout<<" ";
        }
    }
    cout << endl;
}

int selection_sort(vector<int> &a){
    int minj;
    int count=0;
    FOR(i,0,a.size()){
        minj =i;
        FOR(j,i,a.size()){
            if (a[j]<a[minj]){
                minj=j;
            }
        }
        if(i<minj){
        int n   =a[i];
        a[i]    =a[minj];
        a[minj] =n;
        count++;
        }
    }
    return count;
}
