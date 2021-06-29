#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>//sort法  昇順 std::sort(v.begin(),v.end()); 降順 std::sort(v.begin(),v.end(),std::greater<int>());
#include <queue>//積ん読　　stack<TYPE> s(SIZE); s.push(TYPE); s.pop(TYPE); s.top();
#include <stack>//待ち行列　queue<TYPE> q(SIZE); q.push(TYPE); q.pop(TYPE); s.front(); s.back();


#define REP(i, f, t) for(int i=f;i<t;i++)
#define rep(i,t) REP(i,0,t)
#define repV(i, t, v)  { int tmpForRep; rep(i,t) {cin >> tmpForRep; v.push_back(tmpForRep); } }

#define vInt std::vector<int>
#define vPairInt std::vector< std::pair<int,int> >

bool showvInt(vInt v, int begin = 0) { 
	if (v.size() > begin) {
		std::cout << v[begin];
		REP(i, begin + 1, v.size()) {
			std::cout << " " << v[i];
		}
		std::cout << std::endl;
		return true;
	} 
	return false;
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

int main() {
	int n = 0;
	cin >> n;

	vInt v; repV(i, n, v);//0<=v[i]<=10000

	const int K = 10000 + 1;
	vInt vC(K);

	rep(i,n) vC[v[i]]++;

	REP(i,1,K) vC[i] += vC[i - 1];

	vInt vB(n+1);

	for (int i = n - 1; i >= 0; i--) {
		vB[vC[v[i]]] = v[i];
		vC[v[i]]--;
	}

	showvInt(vB,1);

	return 0;
}
