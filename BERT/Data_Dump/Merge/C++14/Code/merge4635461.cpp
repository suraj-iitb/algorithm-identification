#include <iostream>
#include <queue>
using namespace std;
const int INF = 1e9+1;
int cnt = 0;
queue<int> merge(queue<int> a,queue<int> b){
    queue<int> ans;
    a.push(INF); b.push(INF);
    while(a.front() != INF || b.front() != INF){
        if(a.front() <= b.front()){
            ans.push(a.front());
            a.pop(); cnt++;
        }
        else if(b.front() < a.front()){
            ans.push(b.front());
            b.pop(); cnt++;
        }
    }
    return ans;
}
queue<int> mergeSort(queue<int> q){
    if(q.size() == 1) return q;
    queue<int> left,right,a,b;
    int size = q.size();
    for(int i =0; i < size; ++i){
        if(i < size/2){
            left.push(q.front());
            q.pop();
        }
        else{
            right.push(q.front());
            q.pop();
        }
    }
    a = mergeSort(left);
    b = mergeSort(right);
    return merge(a,b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    queue<int> a; 
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        a.push(x);
    }
    queue<int> ans = mergeSort(a);
    int i = 0;
    while(!ans.empty()){
        if(i) cout << " ";
        cout << ans.front(); ans.pop();
        i++;
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
