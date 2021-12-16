//#include<iostream>
//#include <algorithm>
//using namespace std;
//char letter[16];
//int point[16];
//bool visited[16];
//pair<int, char>p[16];
//// n은 현재 숫자, m은 L, c는 C 
////void DFS(int n, int m, int c) {
////	if (n <= m) {
////		cout << p[n].second;
////		DFS(n + 1, m, c);
////	}
////	if (n > m && n <= c) {
////		p[m].second = p[n].second;
////		DFS(1, m, c);
////	}
////}
//int l, c;
//
//void DFS(int idx, int cnt, int vowel, int consonant) {
//	if (cnt == l) {
//		if (vowel >= 1 && consonant >= 2) {
//			for (int i = 1; i <= cnt; i++) {
//				cout << letter[i];
//			}cout << endl;
//		}
//		return;
//	}
//	for (int i = idx + 1; i <= c; i++) {
//		if (!visited[i]) {
//			visited[i] = true;
//			letter[cnt + 1] = letter[i];
//			if (letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'i' || letter[i] == 'o' || letter[i] == 'u') {
//				DFS(i, cnt + 1, vowel + 1, consonant);
//			}
//			else DFS(i, cnt + 1, vowel, consonant + 1);
//			visited[i] = false;
//		}
//	}
//}
//
//
//int main() {
//	cin >> l >> c;
//	for (int i = 1; i <= c; i++) {
//		cin >> letter[i];
//		cout << "char" << letter[i] << "int" << (int)letter[i] << endl;
//	}
//	sort(letter, letter + c);
//	DFS(0, 0, 0, 0);
//
//
//
//
//
//	return 0;
//}

#include <iostream>
using namespace std;
int arr[11];
//int ans = 0;
int total = 0;
bool flag = false;// DFS에 필요한것-> arr의 어떤 상태를 체크해주는 무언가
//여기서는 bool이지만, visited배열이 될수도 있고, 그런것임/
int number;
void DFS(int n, int sum) {
	if (flag == true) return; // 기저 조건
	if (n == number + 1) {
		if (sum == total - sum) {
		//	cout << "YES" << endl;
			flag = true;
			return;
		}
	}
	else {
		DFS(n + 1, sum + arr[n]);
		DFS(n + 1, sum);
	}
}
int main() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	DFS(1 ,0);
	if (flag == false) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}









































/*



#include <iostream>
#define endl "\n"
#include <vector>
using namespace std;
vector<vector<int>>adj;
vector<bool> visited;
void DFS(int here) {
	cout << "DFS visits" << here << endl;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) DFS(there);
	}
}

void DFSALL() {
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < adj.size(); i++) {
		if (visited[i] == NULL) {
			DFS(i);
		}
	}
}
int main() {

	
	return 0;
}*/