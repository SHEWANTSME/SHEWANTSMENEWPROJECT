//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//#define endl "\n"
//using namespace std;
//int arr[10][10];
//int row[10][10];
//int col[10][10];
//int box[10][10];
//vector<pair<int, int>> pp;
//vector<int>v;
//unordered_map<int, int > p;
//int cnt = 0;
//// 1. 가로로 봤을때 visit 체크
////2. 세로로 봤을때 visit 체크
//// 3. 박스 안에서 봤을때 visit 체크
//void ROW(int a, int b) {
//	for (int i = 0; i < 9; i++) {
//		if(row[a][i]!=1)
//	}
//}
//void SUDOKU(int cnt) {
//	int x = cnt / 9;
//	int y = cnt % 9;
//	if (arr[x][y] == 0) {
//
//	}
//}
//void COL(int a, int b) {
//
//}
//void BOX(int a, int b) {
//
//}
//int main() {
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] == 0) {
//				pp[cnt] = { i,j };
//				cnt++;
//			}
//			else {
//				row[i][arr[i][j]] = 1;
//				col[j][arr[i][j]] = 1;
//				box[(i / 3) * 3 + (j / 3)][arr[i][j]] = 1;
//			}
//		}
//	}
//	if (cnt == 0) {
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				cout << arr[i][j] << " ";
//			} cout << endl;
//		}
//	}
//	else {
//		for (int i = 0; i < cnt; i++) {
//			ROW(pp[i].first, pp[i].second);
//		}
//	}
//	return 0;
//}


#include<iostream>

#define endl "\n"

using namespace std;

int arr[9][9];
bool Row[9][9];
bool Col[9][9];
bool BOX[9][9];
void DFS(int cnt){
	int x = cnt / 9;    // x 좌표
	int y = cnt % 9;    // y 좌표

	if (cnt == 81){
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	if (arr[x][y] == 0){
		for (int i = 1; i <= 9; i++)
			if (Row[x][i] == false && Col[y][i] == false && BOX[(x / 3) * 3 + (y / 3)][i] == false){
				Row[x][i] = true;
				Col[y][i] = true;
				BOX[(x / 3) * 3 + (y / 3)][i] = true;
				arr[x][y] = i;
				DFS(cnt + 1);
				arr[x][y] = 0;
				Row[x][i] = false;
				Col[y][i] = false;
				BOX[(x / 3) * 3 + (y / 3)][i] = false;
			}
	}
	else DFS(cnt + 1);
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				Row[i][arr[i][j]] = true;
				Col[j][arr[i][j]] = true;
				BOX[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	

	DFS(0);
	return 0;
}
