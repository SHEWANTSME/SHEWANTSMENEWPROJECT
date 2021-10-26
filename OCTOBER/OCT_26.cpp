#include <iostream>
#include <vector>
using namespace std;

void findcoin(int a, vector<int> &v,int cnt) {
	int alpha = a / v.back();
	if (a - (alpha*v.back()) == 0) { cnt = cnt + alpha; }// { cout << alpha << endl; }
	else {
		a = a - (alpha*v.back());
		cnt = cnt + alpha;
		while (v.back() > a) {
			v.pop_back();
		}
		findcoin(a, v, cnt);
	}

	cout << cnt << endl;
	exit(0);
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	while (v.back() > k) {
		v.pop_back();
	}
	findcoin(k, v, 0);
	
}