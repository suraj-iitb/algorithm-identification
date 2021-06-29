#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <unordered_map>
using namespace std;


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

bool compare_by_b(tuple<int, string, int> a, tuple<int, string, int> b) {
    if(get<2>(a) != get<2>(b)){
        return get<2>(a) > get<2>(b);
    }
}

bool compare_by_string(tuple<int, string, int> a, tuple<int, string, int> b) {
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) < get<1>(b);
    }else{
      	return get<2>(a) > get<2>(b);
    }
}

int check(vector<int> &v, int k, long weight)
{
  int i=0;
  for(int j=0;j<k;j++)
  {
    long tmp = 0;
    while(tmp + v[i] <= weight)
    {
      tmp += v[i];
      i++;
      if(i == v.size()) return v.size();
    }
  }
  return i;
}


long binary_search(vector<int> &v, int k)
{
	long left = 0;
  	long right = v.size() * 10000; //適宜書き換え
  	long mid;
  	while(right - left > 1)
    {
      	mid = (left + right) / 2;
      	int num = check(v,k,mid);
      	if(num >= v.size()) right = mid;
      	else left = mid;
    }
  	return right;
}

bool isComb(vector<int> &elem, int idx, int sum)
{
  if(sum == 0) return true;
  else if(idx >= elem.size() || sum < 0) return false;
  return isComb(elem, idx+1, sum) || isComb(elem, idx+1, sum - elem[idx]);
}

int Merge(vector<int> &v, int left, int mid, int right)
{
  int count = 0;
  int n_left = mid -left;
  int n_right = right -mid;
  vector<int> v_left(n_left);
  vector<int> v_right(n_right);
  for(int i=0;i<n_left;i++) v_left[i] = v[left+i];
  for(int i=0;i<n_right;i++) v_right[i] = v[mid+i];
  int i=0,j=0;
  for(int k=left;k<right;k++)
  {
    count++;
    if(i < n_left && j < n_right && v_left[i] <= v_right[j])
    {
      v[k] = v_left[i];
      i++;
    }
    else if(i < n_left && j < n_right && v_left[i] > v_right[j])
    {
      v[k] = v_right[j];
      j++;
    }
    else if(i < n_left && j >= n_right)
    {
      v[k] = v_left[i];
      i++;
    }
    else if(i >= n_left && j < n_right)
    {
      v[k] = v_right[j];
      j++;
    }
  }
  return count;
}

int MergeSort(vector<int> &v, int left, int right)
{
  int count = 0;
  if(left + 1 < right)
  {
    int mid = (left + right) / 2;
    count += MergeSort(v, left, mid);
    count += MergeSort(v, mid, right);
    count += Merge(v, left, mid, right);
  }
  return count;
}

int Partition(vector<tuple<int, string, long>> &v, int p, int r)
{
  int x = get<2>(v[r]);
  int i = p-1;
  tuple<int, string, long> tmp;
  for(int j=p;j<r;j++)
  {
    if(get<2>(v[j]) <= x)
    {
      i++;
      tmp = v[j];
      v[j] = v[i];
      v[i] = tmp;
    }
  }
  tmp = v[r];
  v[r] = v[i+1];
  v[i+1] = tmp;
  return i+1;
}

/*
Quicksort(A, p, r)
1 if p < r
2    then q = Partition(A, p, r)
3        run Quicksort(A, p, q-1)
4        run Quicksort(A, q+1, r)
*/
void QuickSort(vector<tuple<int, string, long>> &v, int p, int r)
{
  if(p < r)
  {
    int q = Partition(v, p, r);
    QuickSort(v, p, q-1);
    QuickSort(v, q+1, r);
  }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
  	const long div = 1000000007;
	int n;
  	cin >> n;
  	vector<tuple<int, string, long>> A(n);
  	int idx = 0;
  	string suit;
  	long num;
  	while(cin >> suit >> num)
    {
      A[idx] = make_tuple(idx, suit, num);
      idx++;
    }
	QuickSort(A, 0, n-1);
  	bool isStable = true;
  	for(int i=1;i<n;i++)
    {
      if(get<2>(A[i-1]) == get<2>(A[i]) && get<0>(A[i-1]) > get<0>(A[i]))
        isStable = false;
    }
  	if(isStable) cout << "Stable" << endl;
  	else cout << "Not stable" << endl;
  	for(int i=0;i<n;i++) cout <<  get<1>(A[i]) << " " << get<2>(A[i]) << endl;
  	return 0;
}

