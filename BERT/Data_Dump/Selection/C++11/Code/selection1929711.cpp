#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

void printIntInLine(vector<int> &arr) {
	for(vector<int>::iterator itr=arr.begin(); itr!=--(arr.end()); ++itr) {
		printf("%d ", *itr);
	}
	printf("%d\n", *(--(arr.end())));
}

int main() {
    int n, tmp, nSwap;
    vector<int> arr;

    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    nSwap = 0;

    for(auto itr=arr.begin(); itr!=arr.end(); ++itr) {
        auto mini = itr;
        for(auto itr2=itr; itr2!=arr.end(); ++itr2) {
            if(*itr2 < *mini) {
                mini = itr2;
            }
        }
        if(itr != mini) {
            swap(*itr, *mini);
            ++nSwap;
        }
    }

    printIntInLine(arr);
    printf("%d\n", nSwap);
}
