#include <vector>
#include <cstdio>
#include <climits>
#include <iostream>

int main(){
	int v, e;
	std::scanf("%d %d", &v, &e);
	//v = 4; e = 6; r = 0;
	std::vector<std::vector<int>> distance(v, std::vector<int>(v, INT_MAX));
	std::vector<std::vector<int>> to(v);
	std::vector<std::vector<int>> from(v);
	for (auto i = 0; i < e; ++i){
		int s, t, d;
		std::scanf("%d %d %d", &s, &t, &d);
		distance.at(s).at(t) = d;
		to.at(s).push_back(t);
		from.at(t).push_back(s);
	}
	//f(0,1,2,distance,to,from);f(0,2,3,distance,to,from);f(1,2,-5,distance,to,from);f(1,3,1,distance,to,from);f(2,3,2,distance,to,from);f(3,1,0,distance,to,from);
	bool negative = false;
	for (auto i = 0; i < v; ++i){
		distance.at(i).at(i) = 0;
	}
	for (auto k = 0; k < v; ++k){
		for (auto i : from.at(k)){
			for (auto j : to.at(k)){
				//std::cout << "k = " << k << " i = " << i << " j = " << j << "dist" << distance.at(i).at(j) << "-" << distance.at(i).at(k) << "-" << distance.at(k).at(j) << std::endl;
				if (distance.at(i).at(j) > distance.at(i).at(k) + distance.at(k).at(j)){
					if (distance.at(i).at(j) == INT_MAX and i != j){
						to.at(i).push_back(j); from.at(j).push_back(i);
					}
					distance.at(i).at(j) = distance.at(i).at(k) + distance.at(k).at(j);
				}
			}
			if (distance.at(i).at(i) < 0){
				negative = true;
				k = v - 1;
			}
		}
	}
	if (negative){
		std::printf("NEGATIVE CYCLE\n");
	}else{
		for (auto i = 0; i < v; ++i){
			if (distance.at(i).at(0) < INT_MAX){
				std::printf("%d", distance.at(i).at(0));
			}else{
				std::printf("INF");
			}
			for (auto j = 1; j < v; ++j){
				if (distance.at(i).at(j) < INT_MAX){
					std::printf(" %d", distance.at(i).at(j));
				}else{
					std::printf(" INF");
				}
			}
			std::printf("\n");
		}
	}
}
