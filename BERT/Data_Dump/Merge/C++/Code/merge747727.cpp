/*
今回は　入力される値の最大値がわかっているので、sentinelを使った実装にする
*/

#include <iostream>
#include <vector>

#define SENTINEL 1000000001 //10^9 + 1

using namespace std;

int count=0;


void Merge(vector<int>& A, int left, int mid, int right){
	int i,j,k;
	int n1 = mid-left+1;
	int n2 = right - mid;
	vector<int> L;
	vector<int> R;

	for(i=0; i<n1; i++) L.push_back(A.at(left+i));
	for(i=0; i<n2; i++) R.push_back(A.at(mid+i+1));

	//sentinelを入れる。
	L.push_back(SENTINEL);
	R.push_back(SENTINEL);

	i=0;
	j=0;
	for(k=left; k<=right; k++){
		count++; //比較回数数える
		if( L.at(i)<=R.at(j) ){
			A[k] =L.at(i); //vectorへの上書きこれでいいのか？
			i++;
		}
		else{
			A[k] =R.at(j); //vectorへの上書きこれでいいのか？
			j++;
		}
	}
}


void Merge_Sort(vector<int>& A, int left, int right){
	int mid;

	if(left+1<=right){ //要素が２つ以上あったら
		mid =(left+right)/2;
		Merge_Sort(A, left, mid);
		Merge_Sort(A, mid+1, right);
		Merge(A, left, mid, right);
	}

}


int main() {
    int i,j;
	int buf, n;
    vector<int> S; //AとSどちらにしようか迷ったが、mainの中ではSにした。
    
    cin >> n;
	for(i=0;i<n;i++) {
		cin >> buf;
		S.push_back(buf);
	}

	Merge_Sort(S, 0, n-1);
    
	for(i=0;i<n;i++) {
		cout << S.at(i);
		if(i!=n-1) cout << ' '; else cout << endl; //スペース出すか、改行だすか
	}
	cout << count << endl;
	
	return 0;
}
