/*
vrrtll==???>;::::~~~~~~......`.`````````````````````...-?777!_.._?7u,~~~::::;>>??=lllttrrzu
rtll==??>>;::::~~~~......`.`````````````````` ..J77!`````````...`..._T,~~~~:::;;>??==lttrrv
tll=??>>;:::~~~~......``````````````````..J7^ ` ``  ` `` .,```````...._4,.~~~::;;>>?===lttr
l=???>;;::~~~......`````HTSu,.``  `..J7!    `      `` .J"~N```````````..?&.~~~~::;;>>?==llt
=??>;;::~~~~.....``````.@????7SJ.?=     `     ` `` .J=....J;  ``````````..h..~~~~::;;>??=ll
?>>;::~~~~.....````````.D?>>?>?>?8+.``         `.J"_......_b`     ````````.S_.~~~~::;;>??=l
>;;::~~~~....``````````.C>??>>>?>>>?8J.`  ```..Y~..........J;  `  ` ``````` G...~~~~::;>??=
;;::~~~....```````` `..W1>>?>>>>?>>>>>?S,.`.7^.............-N``  `   ``````` 6...~~~~::;>??
;:~~~~....``````` ..7` d??>>?>?>>?>>?>>1udMgggNNNNggJ.......([          `````.L...~~~~::;>?
:~~~.....`````` .7`   `K>?>?>>>>>>+ugNMMMB""7<!~~<?7TWMNNa,..w.`  ` `  ` `````,)....~~:::;>
~~~....``````.J^     ` #>>?>>>?jgMMM9=_................-?TMMa,b` `   `  `  ````(,...~~~~:;;
~~~....``` .7``   `    @?>>?1uMM#=.........................(TMNa......  ` ``````4....~~~::;
~~~...`` .=`` `     ` .b>>jgNH".................`.............?HNmx??17TYY9SA+(..L....~~~::
~....` ,^``     `   ` .b+dN#^............6..-(,-...`............(HMm+>>>>>?>>????zOM_.~~~::
.... .=```  `` `   ...JNMM^..........`..._n.(MMN,....`..`.........?MNe<>>?>??>????d^...~~~:
~...v```` ` ..-Z""!_..(M@_........`........?7MMMMp.................-TNN+?>>>????1d4-..-(Jk9
..(^`...zY"!_........(MD..............`......JMMMMp....`..`..`......./MNx>??>>?1d!.h7=~(??=
(v_`,R_.............(NF..(/..(&,...`..........?MMMM;..................(MMs>>?1&T"!``....(1=
t..`` 4,...........(N@....?,(NMNR_.....`..`....(WMM$..`....`..`..`....._HMe7=```````....~_1
...````.4,........-dM:.....(7MMMNR-.....................`............(.?^ ``  ``````....~~~
...``````,4,....`.(NF........(MMMMb..`....--................`....(.7!        `  ````....~~:
..````` ` `.5J_...JMt.........?NMMM[...`.HH5._(J7[...`...`...--?^`          ` `````....~~~:
...````` `  ` 7a,.dM{....`...../MMMN......(J=`  .>......._(/=             `  ` `````...~~~:
....```` ``     (4MN{..........._7"^...(/^    `.C....-(J=`                  ` ` ```....~~~:
....````` `      JdM[...`...`........`_3..  ..?!..(-7!                  ` ` ``````....~~~::
r...``````  ` ``(CJMb..............`......__..-(?^                     `  `  `````....~~::;
J/...````` `  `,3>+MN-.`..`...`..........._(J=``                     `  ` ```````....~~~::;
_j,..`.```` ``.5>>?dNb...`......`......_-?'`                            `  `````....~~~::;;
~~j,..```````.D??>>>MM/....`........(-=`                          `  ` ` ```````...~~~:::;>
~~~j,...````.E??>??>?MN-.........(J=                            `   ` ` ``````....~~~~::;??
:~~~?,...``.@>?>?>>??dMN_....-(?^                        `  `    ` `  ````````...~~~~:;;>??
::~~~?/....K??????>>?>dMN-_(7!                               `  ` ` ````````....~~~:::>>??l
;:::~~/e.(K==?????????<dM"!                          `    `   ` ` `` ``````...~~~~:::;>??=l
*/
#include "bits/stdc++.h"
using namespace std;
#define ok1 printf("ok1\n")
#define ok2 printf("ok2\n")
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=(s);i<(n);++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define REPR(i,s,n) for(int i=(s);i>=(n);--(i))
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb emplace_back //emplace_backの方が速いが使い慣れてないため
#define DOUBLE fixed << setprecision(15)
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define BIT(n,m)(((n)>>(m))&1)
const double pi = acos(-1.0);
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef deque<ll> dll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> TLL;
typedef vector<P> vP;
typedef vector<TLL> vTLL;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
ll dy[4] = { 1,0,-1,0 };
ll dx[4] = { 0,1,0,-1 };
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>&p) {
	ost << "{" << p.first << ", " << p.second << "} ";
	return ost;
}
template<class T>
ostream& operator<<(ostream& ost, const vector<T>&v) {
	ost << "{";
	for (int i = 0; i<v.size(); i++) {
		if (i)ost << ", ";
		ost << v[i];
	}
	ost << "} ";
	return ost;
}
template<class A, class B>
ostream& operator<<(ostream& ost, const map<A, B>&v) {
	ost << "{";
	for (auto p:v) {
		ost << "{" << p.first << ", " << p.second << "} ";
	}
	ost << "} ";
	return ost;
}
bool out_check(ll a, ll b) { return (0 <= a && a < b); }
void addmod(ll &a, ll &b) { a = (a + b) % mod; }
double pitagoras(ll a, ll b, ll c, ll d) {
	double dx = a - b, dy = c - d;
	return pow(dx * dx + dy * dy, 0.5);
}
ll powmod(ll a, ll b) { ll c = 1; while (b > 0) { if (b & 1) { c = a * c%mod; }a = a * a%mod; b >>= 1; }return c; }
void Yes(bool x) { cout << ((x) ? "Yes\n" : "No\n"); }
void YES(bool x) { cout << ((x) ? "YES\n" : "NO\n"); }
void yes(bool x) { cout << ((x) ? "yes\n" : "no\n"); }
void Yay(bool x) { cout << ((x) ? "Yay!\n" : ":(\n"); }
vector<string> DAY = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
ll  n, m, d, e, r, l, k, h, ans, ret = M;
bool flag = false, flag2 = false, flag3 = false;
string s, t, u;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);//not intractive
	cin >> n;
	vll v(n);
	rep(i, n)cin >> v[i];
	rep(i, n) {
		repr(j, i) {
			if (v[j] < v[j + 1])break;
			else swap(v[j], v[j + 1]);
		}
		rep(i, n) {
			if (i != 0) cout << " ";
			cout << v[i];
		}
		cout << endl;
	}
}

