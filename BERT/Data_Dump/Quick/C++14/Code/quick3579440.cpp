#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

struct Card{
    ll v;
    char c;

    Card(ll _v, char _c){
        v = _v;
        c = _c;
    }
    Card(){}
    
    bool operator<(const Card &another) const
    {
        return v < another.v;
    }

    string ToString(){
        stringstream ss;
        ss << c << ' ' << v;
        return ss.str();
    }
};

ll partition(vector<Card>& A, ll p, ll r){
    ll x = A[r].v;
    ll i = p-1;
    FOR(j, p, r){
        if(A[j].v<=x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quick_sort(vector<Card>& A, ll p, ll r){
    if(p<r){
        ll q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    vector<Card> A(N);
    FOR(i, 0, N){
        char c;
        ll v;
        cin >> c >> v;
        A[i] = Card(v, c);
    }

    auto B = A;

    quick_sort(A, 0, N-1);
    stable_sort(ALL(B));

    bool is_stable = true;
    FOR(i, 0, N){
        auto a = A[i];
        auto b = B[i];
        if(a.v==b.v && a.c==b.c){
            //
        }else{
            is_stable = false;
        }
    }
    
    if(is_stable){
        p("Stable");
    }else{
        p("Not stable");
    }

    FOR(i, 0, N){
        p(A[i].ToString());
    }
    
    return 0;
}
