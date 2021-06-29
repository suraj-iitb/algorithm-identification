#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct VertexDistance {

	int first;
	int second;

	VertexDistance(int f, int s) : first(f), second(s) {}

};

bool operator< (const VertexDistance &a, const VertexDistance &b) {
	return a.second > b.second;
}
		

int v, e, startVertex;
vector<vector<pair<int, int> > > vertex;
priority_queue <VertexDistance> que;
int vertexDistance[100005];
char visitedVertex[100005];

const char Yet = '1';
const char Now = '2';
const char Finish = '3';
const int INF = 1 << 30;

void Init();

int main() {



	cin >> v >> e >> startVertex;

	Init();

	for (int i = 0; i < e; ++i) {

		int s, t, d;
		cin >> s >> t >> d;

		vertex[s].push_back(make_pair(t, d));

	}

	/*
	for (int i = 0; i < v; ++i) {
		cout << i << " : ";
		for (int j = 0; j < vertex[i].size(); ++j) {
			cout << vertex[i][j].first << "->" << vertex[i][j].second << ", ";
		}
		cout << endl;
	}
	*/

	que.push(VertexDistance(startVertex, 0));

// 	cout << endl << endl;

	while (!que.empty()) {

		VertexDistance nowVertex = que.top();
		que.pop();
		int nowV = nowVertex.first;
		int nowD = nowVertex.second;

		if (visitedVertex[nowV] == Finish)
			continue;


		visitedVertex[nowV] = Finish;
		vertexDistance[nowV] = nowD;
//		cout << nowV << " : " << nowD << endl;
		for (int i = 0; i < vertex[nowV].size(); ++i) {

			if (visitedVertex[vertex[nowV][i].first] != Finish) {
				que.push(VertexDistance(vertex[nowV][i].first, vertex[nowV][i].second + nowD));
			}



		}

	}

//	cout << endl << endl;

	for (int i = 0; i < v; i++) {
		if (vertexDistance[i] == INF)
			cout << "INF" << endl;
		else
			cout << vertexDistance[i] << endl;
	}

	return 0;
}

void Init() {

	for (int i = 0; i < v; ++i) {
		vertexDistance[i] = INF;
		visitedVertex[i] = Yet;
		vertex.push_back(vector<pair<int, int> >());
	}


}


