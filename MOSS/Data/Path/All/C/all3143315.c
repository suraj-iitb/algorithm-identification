#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

#define MAX_COST (10000000000)


int main(int argc, char **argv){
	int n, m;
	std::vector<std::vector<long long> > min_cost;
	bool is_there_negative_cycle = false;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	//FILE *fp = fopen("test.txt", "r");
#endif


#if INPUT_FROM_FILE
	ifs >> n >> m;
#else
	std::cin >> n >> m;
#endif


	min_cost.resize(n);
	for(int i = 0; i < n; i++){
		min_cost[i].resize(n, MAX_COST);
		min_cost[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		int s, t, d;

#if INPUT_FROM_FILE
		ifs >> s >> t >> d;
#else
		std::cin >> s >> t >> d;
#endif
		min_cost[s][t] = d;
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(min_cost[i][j] == MAX_COST){
					if(min_cost[i][k] == MAX_COST || min_cost[k][j] == MAX_COST){
						min_cost[i][j] = MAX_COST;
					}
					else{
						min_cost[i][j] = min_cost[i][k] + min_cost[k][j];
					}
				}
				else{
					min_cost[i][j] = std::min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(min_cost[i][i] < 0){
			is_there_negative_cycle = true;
			break;
		}
	}
	

	if(is_there_negative_cycle){
		std::cout << "NEGATIVE CYCLE" << std::endl;
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(min_cost[i][j] == MAX_COST){
					std::cout << "INF";
				}
				else{
					std::cout << min_cost[i][j];
				}
				if(j < n - 1){
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
