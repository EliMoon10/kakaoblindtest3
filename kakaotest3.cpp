#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int works() {
	int cacheSize = 0;
	vector<string> cities = {
		"Jeju",
		"Pangyo",
		"Seoul",
		"NewYork",
		"LA",
		"Jeju",
		"Pangyo",
		"Seoul",
		"NewYork",
		"LA"
	};

	int cost = 0;
	deque<string> cache;
	for (int i = 0; i < cities.size(); i++) {
		cost += 5;
		for (deque<string>::iterator iter = cache.begin(); iter != cache.end(); iter++) {
			if (iter->compare(cities[i]) == 0) {
				cost -= 4;
				break;
			}
		}
		cache.push_back(cities[i]);
		if (cache.size() > cacheSize)
			cache.pop_front();
	}

	cout << cost << endl;
}

int main() {
	works();

	return 0;
}

