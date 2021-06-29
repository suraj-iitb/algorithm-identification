#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<cassert>
#include<functional>
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int length;
	int minj;
	int count = 0;
	
	std::cin >> length;
	std::vector<int> input(length);
	for (int i = 0; i < length; i++){
		std::cin >> input[i];
	}

	for (int i = 0; i < length; i++){
		minj = i;
		for (int j = i; j < length; j++){
			if (input[minj] > input[j]){
				minj = j;
			}
		}
		if (i != minj){
			std::swap(input[minj], input[i]);
			count++;
		}
	}

	for (int i = 0; i < length; i++){
		std::cout << input[i];
		if (i != length - 1){
			std::cout << ' ';
		}
		else{
			std::cout << '\n';
		}
	}
	std::cout << count << '\n';

	return 0;
}
