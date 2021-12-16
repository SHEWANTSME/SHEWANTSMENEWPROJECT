//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int N, r, c;
//int ans = 0;
//vector<pair<int, int>>p;
//int sector;
//int findsector(int n, int row, int col) {
//	if (row >= pow(2, n - 1) && col >= pow(2, n - 1)) return 4;
//	else if (row < pow(2, n - 1) && col >= pow(2, n - 1)) return 2;
//	else if (row >= pow(2, n - 1) && col < pow(2, n - 1)) return 3;
//	else return 1;
//}
//void findans(int ans, int n) {
//	if (n == N) return;
//	int se = findsector(n + 1, p[n + 1].first, p[n + 1].second);
//	int x = pow(2, n)* pow(2, n);
//	if (se == 4) { ans = x * 3 + ans; findans(ans, n + 1); }
//	if (se == 3) { ans = x * 2 + ans; findans(ans, n + 1); }
//	if (se == 2) { ans = x + ans; findans(ans, n + 1); }
//	if (se == 1) { findans(ans, n + 1); }
//}
//void DFS(int n, int row, int col, int sec/*, bool beta*/) {
//	//if (n == N && beta == true) return;
//	if (n == 1) {
//		ans = sec - 1;
//		findans(ans, 1);
//	}
//	if (n != 1) {
//		if (sec == 4) {
//			row -= pow(2, n - 1);
//			col -= pow(2, n - 1);
//		}
//		else if (sec == 3) {
//			row -= pow(2, n - 1);
//		}
//		else if (sec == 2) {
//			col -= pow(2, n - 1);
//		}
//		int newsector = findsector(n, row, col);
//		p[n].first = row;
//		p[n].second = col;
//		DFS(n - 1, row, col, newsector);
//	}
//
//}
//int main() {
//	cin >> N >> r >> c;
//	// find which sector does this numbers located in.
//	p.resize(N + 1);
//	p[0].first = 0;
//	p[0].second = 0;
//	sector = findsector(N, r, c);
//	DFS(N, r, c, sector);
//
//	cout << ans << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int v[51];
//int ans[51];
char x[101][101];
int ans[101][101];
int main() {
	
	int n, s; cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s; j++) {
			cin >> x[i][j];
			
		}
	}
	
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		bool check = false;
		for (int j = 0; j < s; j++) {
			if (x[i][j] == 'c') {
				ans[i][j] = 0;
				check = true;
				cnt = 0;
			}
			if(x[i][j]!='c' && check==true) {
				cnt++;
				ans[i][j] = cnt;
			}
			if (x[i][j] != 'c' && check == false) {
				ans[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s; j++) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}

	/*
	
	ans[i][0] = s+v[i]
	ans[i][1] = s-v[i]
	ans[n][0] = ans[n-1][0]
	
	
	*/
	
	return 0;
}