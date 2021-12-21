#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include<queue>
#include<deque>
using namespace std;
int arr[51][51];
bool check[51][51];
int dx[4] = { -1,1,0,0, };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
int row, col;
void DFS(int garo, int sero) {
	check[garo][sero] = 1;
	for (int k = 0; k < 4; k++) {
		int ng = garo + dx[k];
		int ns = sero + dy[k];
		if (ng >= 0 && ng < row && ns >= 0 && ns < col) {
			if (arr[ng][ns] == 1) {
				if (check[ng][ns] == 0) {
					DFS(ng, ns);
				}
			}
		}
		else continue;
	}		
}
int main() {
	int testcase; 
	cin >> testcase;
	while (testcase--) {
		int garo, sero, baechu;
		cin >> garo >> sero >> baechu;
		row = garo;
		col = sero;
		while (baechu--) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < garo; i++) {
			for (int j = 0; j < sero; j++) {
				if (arr[i][j] == 1) {
					if (check[i][j] == 0) {
						cnt++;
						DFS(i, j);
					}
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				check[i][j] = 0;
			}
		}
		cnt = 0;
	}
	
	return 0;
}