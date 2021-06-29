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
	int count = 0;
	bool flag = false;

	std::cin >> length;
	std::vector<int> input(length);
	for (int i = 0; i < length; i++){
		std::cin >> input[i];
	}

	while (flag == false){
		flag = true;
		for (int i = length - 1; i >= 1; i--){
			if (input[i] < input[i - 1]){
				std::swap(input[i], input[i - 1]);
				count++;
				flag = false;
			}
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
