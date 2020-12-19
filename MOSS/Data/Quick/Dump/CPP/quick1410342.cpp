#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

struct card {
	char mark;
	int num;
	bool operator!=(card c) const {
		return this->num != c.num || this->mark != c.mark;
	};
	bool operator<=(card c) const {
		return this->num <= c.num;
	};
	bool operator<(card c) const {
		return this->num <= c.num;
	};
};

queue<card> merge(queue<card> q1, queue<card> q2){
	queue<card> ma;
	while(q1.size() || q2.size()){
		if(!q2.size() || (q1.size() && q1.front() < q2.front())){
			ma.push(q1.front());
			q1.pop();
		}else{
			ma.push(q2.front());
			q2.pop();
		}
	}
	return ma;
}
queue<card> sort(queue<card> q){
	queue<card> nq;
	while(q.size() - nq.size() > 1){
		nq.push(q.front());
		q.pop();
	}
	if(!nq.size()) return q;
	return merge(sort(nq), sort(q));
}

int partition(card *A, int p, int r){
	card x = A[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++){
		if(A[j] <= x){
			swap(A[j], A[++i]);
		}
	}
	swap(A[r], A[++i]);
	return i;
}

bool isStable(queue<card> q, card *c){
	int i = 0;
	while(q.size()){
		if(q.front() != c[i++]) return false;
		q.pop();
	}
	return true;
}

void sort(card *A, int p, int r){
	if(r-p < 1) return;
	int pivot = partition(A, p, r);
	sort(A, p, pivot-1);
	sort(A, pivot+1, r);
}

int main() {
	int n;
	cin >> n;
	
	card d[n];
	queue<card> qc;
	for(int i = 0; i < n; i++){
		cin >> d[i].mark >> d[i].num;
		qc.push(d[i]);
	}
	
	sort(d, 0, n-1);
	qc = sort(qc);
	
	cout << (isStable(qc, d) ? "S" : "Not s") << "table" << endl;
	for(int i = 0; i < n; i++){
		cout << d[i].mark << " " << d[i].num << endl;
	}
	
    return 0;
}
