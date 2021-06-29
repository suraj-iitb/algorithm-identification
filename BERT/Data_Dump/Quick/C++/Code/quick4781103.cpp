#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>//sort法  昇順 std::sort(v.begin(),v.end()); 降順 std::sort(v.begin(),v.end(),std::greater<int>());
#include <queue>//積ん読　　stack<TYPE> s(SIZE); s.push(TYPE); s.pop(TYPE); s.top();
#include <stack>//待ち行列　queue<TYPE> q(SIZE); q.push(TYPE); q.pop(TYPE); s.front(); s.back();


#define REP(i, f, t) for(int i=f;i<t;i++)
#define rep(i,t) REP(i,0,t)
#define repV(i, t, v)  {  }

#define vInt std::vector<int>
#define vPairInt std::vector< std::pair<int,int> >

template<typename T> void cinV(std::vector< T > &v, int size) { T tmp; rep(i, size) { std::cin >> tmp; v.push_back(tmp); } }
template<typename T1, typename T2> void cinV(std::vector< std::pair<T1,T2> > &v, int size) {
	T1 tmp1; T2 tmp2; rep(i, size) { std::cin >> tmp1 >> tmp2; v.push_back(std::make_pair(tmp1,tmp2));}
}
template<typename T> void coutV(std::vector< T > v, int begin = 0) {
	if (v.size() <= begin) return;
	std::cout << v[begin];
	REP(i, begin + 1, v.size()) std::cout << " " << v[i];
	std::cout << std::endl;
}
template<typename T1, typename T2> void coutV(std::vector< std::pair<T1,T2> > v, int begin = 0) {
	if (v.size() > begin) REP(i, begin, v.size()) std::cout << v[i].first << " " << v[i].second << std::endl;
}


/*pair
std::pair<TYPE,TYPE> p;
p = std::make_pair(TYPE,TYPE);
cout << p.first << " " << p.second << endl;
*/

/* scan char
char* a_tmp[2]; //{' ', '\0'}
scanf("%c", a_tmp);//アルファベット1文字
*/

/*scan str
vector<char> a_tmp;
int n = ;//loop回数

for(int i=0;i<n;i++){
  scanf("%c", a_tmp[i]);
}

*/

/*桁数の指定
//#include<iomanip> 
//もう一度桁数を指定するまでこのまま固定される
cout << std::setprecision(3) << 3.1415 << endl;//3.14
*/

/*回転行列の公式
|cosθ, -sinθ||x| = | xcosθ - ysinθ |
|sinθ,  cosθ||y|   | xsinθ + ycosθ | 
*/

using namespace std;

vector< pair<char, int> > v;

int partition(int p, int r) {
	int x = v[r].second;
	int i = p - 1;

	REP(j, p, r) {
		if (v[j].second <= x) {
			i++;
			swap(v[i], v[j]);
		}
	}

	swap(v[i + 1], v[r]);

	return i + 1;
}

void quickSort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}
}

int main() {
	int n = 0;
	cin >> n;

	cinV(v, n);

	vector< pair<char, int> > v2;//元の順番のベクトル
	v2 = v;

	quickSort(0, v.size()-1);

	bool StableFlag = true;
	rep(i, v.size()) {
		rep(j, v2.size()) {
			if (v[i].second == v2[j].second) {//数字が同じであるとき
				if (v[i].first != v2[j].first) {//マークを確認(Stableならば必ず同じ)
					cout << "Not stable" << endl;
					StableFlag = false;
				}
				v2[j].second = 0;//次に同じ数字を参照使用としたときこれは邪魔なので適当に0で排除しとく
				break;
			}
		}
		if (!StableFlag) break;
	}
	if(StableFlag) cout << "Stable" << endl;
	coutV(v);

	return 0;
}
