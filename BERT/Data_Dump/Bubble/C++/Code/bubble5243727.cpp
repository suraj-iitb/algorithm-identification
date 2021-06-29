#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
int bubbleSort(vector<int> &a);
void vector_cout(vector<int> &a);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n){
        cin >> a[i];
    }
    int count;
    count=bubbleSort(a);
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

int bubbleSort(vector<int> &a){
    int count=0;
    bool IsAdjacent=true;//逆の隣接要素が存在する
    while(IsAdjacent){
        IsAdjacent=false;
        FOR(i,1,a.size()){
             if (a[i]<a[i-1]){
                 //中身入れ替え
                int n=a[i];
                a[i]=a[i-1];
                a[i-1]=n;
                //フラグ立て
                IsAdjacent=true;
                count++;
             }
        }
    }
    return count;
}
