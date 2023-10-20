#include <bits/c++config.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

using namespace std;


// Calculators
long long calc(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else {
		assert(0); // using assertion 
	}
}

// Dynamic programming approach
long long get_maximum_value(const string &str) {
	int n = (str.size() + 1) / 2;
	vector<pair<long long, long long>> solution(n * n);

	auto sol_get = [&solution, &str, n](long long i, long long j) {
		return solution.at(i * n + j);
	};
	auto sol_set = [&solution, &str, n](long long i, long long j,
										pair<long long, long long> value) {
		return solution[i * n + j] = value;
	};

	auto digits = [&str](long long i) { return str.at(2 * i) - '0'; };
	auto op = [&str](long long i) { return str.at(2 * i + 1); };

	for (int i = 0; i < n; i++) {
		sol_set(i, i, make_pair(digits(i), digits(i)));
	}
	long long temp_min, temp_max;
	long long a, b, c, d;

	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			temp_min = numeric_limits<long long>::max();
			temp_max = numeric_limits<long long>::min();
			for (int k = j - i; k < j; k++) {
				a = calc(sol_get(j - i, k).first, sol_get(k + 1, j).first,
						 op(k));
				b = calc(sol_get(j - i, k).second, sol_get(k + 1, j).second,
						 op(k));
				c = calc(sol_get(j - i, k).first, sol_get(k + 1, j).second,
						 op(k));
				d = calc(sol_get(j - i, k).second, sol_get(k + 1, j).first,
						 op(k));
				temp_min = min(temp_min, min(min(a, b), min(c, d)));
				temp_max = max(temp_max, max(max(a, b), max(c, d)));
				sol_set(j - i, j, make_pair(temp_min, temp_max));
			}
		}
	}
	return sol_get(0, str.size() / 2).second;
}

int main() {
	string s;
	cin >> s;
	cout << get_maximum_value(s) << '\n';
}