#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
int arr[10][10];
int check = 0;
vector<pair<int, int>> pp;
// 뻐킹 스도쿠
// 1. 가로로 봤을때 visit 체크
//2. 세로로 봤을때 visit 체크
// 3. 박스 안에서 봤을때 visit 체크
void SUDOKU(int n) {
	if (check == 1) return;
	if (n == pp.size()) {
		for (int a = 0; a < 9; a++) {
			for (int b = 0; b < 9; b++) {
				cout << arr[a][b] << " ";
			}
			cout << endl;
		}
		check = 1;
		return;
	}
	else {
		for (int i = 0; i < 9; i++) {
			int c = 0;
			for (int j = 0; j < 9; j++) {
				if (arr[pp[n].first][j] == i + 1) c = 1;
				if (arr[j][pp[n].second] == i + 1) c = 1;
				if (c == 1) break;
			}
			int x = pp[n].first / 3;
			int y = pp[n].second / 3;
			x = x * 3;
			y = y * 3;
			for (int ii = x; ii <= x + 2; ii++) {
				for (int j = y; j <= y + 2; j++) {
					if (arr[ii][j] == i + 1) c = 1;
				}
				if (c == 1) break;
			}
			if (c == 1)continue; // what does this mean? -> 만약 위의 조건들을 통과못하고 
			// c==1이되면 i값 패스
			arr[pp[n].first][pp[n].second] = i + 1;
			SUDOKU(n + 1);
			arr[pp[n].first][pp[n].second] = 0;
		}
	}



}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) pp.push_back({ i,j });
		}
	}
	SUDOKU(0);
	return 0;
}

//
//#include<iostream>
//
//#define endl "\n"
//
//using namespace std;
//
//int arr[9][9];
//bool Row[9][9];
//bool Col[9][9];
//bool BOX[9][9];
//void DFS(int cnt){
//	int x = cnt / 9;    // x 좌표
//	int y = cnt % 9;    // y 좌표
//
//	if (cnt == 81){
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//		exit(0);
//	}
//
//	if (arr[x][y] == 0){
//		for (int i = 1; i <= 9; i++)
//			if (Row[x][i] == false && Col[y][i] == false && BOX[(x / 3) * 3 + (y / 3)][i] == false){
//				Row[x][i] = true;
//				Col[y][i] = true;
//				BOX[(x / 3) * 3 + (y / 3)][i] = true;
//				arr[x][y] = i;
//				DFS(cnt + 1);
//				arr[x][y] = 0;
//				Row[x][i] = false;
//				Col[y][i] = false;
//				BOX[(x / 3) * 3 + (y / 3)][i] = false;
//			}
//	}
//	else DFS(cnt + 1);
//}
//
//
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] != 0) {
//				Row[i][arr[i][j]] = true;
//				Col[j][arr[i][j]] = true;
//				BOX[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
//			}
//		}
//	
//
//	DFS(0);
//	return 0;
//}
