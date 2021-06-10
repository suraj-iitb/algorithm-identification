#include <iostream>
using namespace std;
int V, E, s, t, d;
long long int K[101][101];
bool B[101][101];
const long long int inf = 100000000000;
int main() {
 cin >> V >> E;
 for (int i=0; i<V; ++i) {
  for (int j=0; j<V; ++j) {
   K[i][j] = (i == j) ? 0 : inf;
   B[i][j] = false;
  }
 }
 for (int i=0; i<E; ++i) {
  cin >> s >> t >> d;
  K[s][t] = d;
  B[s][t] = true;
 }
 for (int k=0; k<V; ++k) {
  for (int i=0; i<V; ++i) {
   for (int j=0; j<V; ++j) {
    if (K[i][j] > K[i][k] + K[k][j] && B[i][k] && B[k][j]) {
	 K[i][j] = K[i][k] + K[k][j];
	 B[i][j] = true;
	}
   }
  }
 }
 bool nc = false;
 for (int i=0; i<V; ++i) {
  if (K[i][i] < 0) {
   cout << "NEGATIVE CYCLE" << endl;
   nc = true;
   break;
  }
 }
 if (!nc) {
  for (int i=0; i<V; ++i) {
   for (int j=0; j<V; ++j) {
    if (K[i][j] == inf) { cout << "INF"; }
	else { cout << K[i][j]; }
    cout << ((j == V-1) ? "" : " ");
   }
   cout << endl;
  }
 }
}
