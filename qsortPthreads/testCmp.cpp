#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int sumDig(int a) {
	int res = 0;
	while (a) {
		res += (a % 10);
		a /= 10;
	}
	return res;
}

int bits(int a) {
	int res = 1;
	while (a) {
		res *= max(1, a % 10);
		a /= 10;
	}
	return res;
}

bool cmp(int u, int v) {
	if (abs(sumDig(u) - sumDig(v)) > 1) {
		return sumDig(u) < sumDig(v);
	}

	if (bits(u) != bits(v)) {
		return bits(u) < bits(v);
	}
	return u < v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	srand(time(NULL));
	int ii = 1e9, jj = ii, kk = ii;
	for (int q = 0; q < 30000000; ++q) {
		int i = rand();
		int j = rand();
		int k = rand();
		if (cmp(i, j) && cmp(j, k) && cmp(k, i)) {
			cout << i << " " << j << " " << k << "\n";
			if (max(i, max(j, k)) < max(ii, max(jj, kk))) {
				ii = i;
				jj = j;
				kk = k;
			}
		}
	}

	cout << ii << " " << jj << " " << kk << endl;

	return 0;
}
