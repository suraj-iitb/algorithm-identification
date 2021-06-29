/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
19：25〜
着席位置は{中央x中央}
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>

using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;
using std::queue;
using std::deque;
using std::priority_queue;
using std::next_permutation;
//using std::iota;
using std::sort;
using std::greater;
using std::max;
using std::min;

#define INF 999999999;
#define MOD 1000000007

#define EVEL 1

#ifndef EVEL
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif

int V, E, r;
//vector< vector < pair<int, int> > > graph;
struct {
    int s;
    int t;
    unsigned long long int d;
} Cost[500005];
unsigned long long int d[100005];

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);

    cin >> V >> E >> r;;
    for(int i = 0; i < V; i++){
        d[i] = 99999999999;
    }
    d[r] = 0;
    for(int i = 0; i < E; i++){
        cin >> Cost[i].s >> Cost[i].t >> Cost[i].d;
        
    }

    bool f = true;
    while(f){
        f = false;
        for(int i = 0; i < E; i++){
            if(d[ Cost[i].t ] > d[ Cost[i].s ] + Cost[i].d){
                d[ Cost[i].t ] = d[ Cost[i].s ] + Cost[i].d;
                f = true;
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(d[i] == 99999999999) cout << "INF\n";
        else cout << d[i] << "\n";
    }

    return 0;
}
