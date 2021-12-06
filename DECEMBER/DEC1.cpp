//#include <iostream>
//#define endl "\n"
//using namespace std;
//
//int n, m;
//int arr[9]; //���ڴ�³�
//bool visited[9]; // üũ�ϴ³�
//void DFS(int cnt){
//	if (cnt == m)	{
//		for (int i = 0; i < m; i++)	cout << arr[i] << " ";
//			cout << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++){// ó���� cnt�� 0 �̴ϱ�
//		if (visited[i]==NULL){ // ��� visited�� 0
//			visited[i] = true; arr[cnt] = i; //visited[1] = 1, arr[0]=1 
//			DFS(cnt + 1); visited[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	DFS(0);
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//int Local(int n) {
//	n += 10;
//	return n; 
//	// ���� �������� Local() �Լ����� �Ű����� n�� �μ��� ���� nk�� ���� ���޹޽��ϴ�.
////	���� �Լ� ������ �Ű����� n�� ���� �ƹ��� �����ϴ��� ���� �μ��� ���޵� ���� nk�� ���� ���� ������� �ʽ��ϴ�.
//}
//int Local2(int &n) {
//	n += 10;
//	return n;
//}
//int main() {
//	int nk = 10;
//	cout << nk << endl;
//	Local(nk);
//	cout << "new nk" << nk << endl;
//	cout << Local(10) << endl; // �׷��� �̷��� ���� �������.  �ƴϸ�
//	Local2(nk);
//	cout << "real new nk" << nk << endl;
//
//	return 0;
//}

#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
//int dp[11][11];
int arr[11][11];
int dp[11][11];
int  visited[11];  // �׻� dfs�� visited�� �ʿ���!!!!!!!
int ans = 0;
int finalans = 0;
void DFS(int n) {
	if (n == 11) {
		finalans = max(ans, finalans);
		//cout << max(finalans, ans) << endl;
		return;
	}
	
	for (int i = 0; i < 11; i++) {
		if (arr[n][i] != 0 && visited[i] == NULL) {
			visited[i] = true;
			ans += arr[n][i];
			DFS(n + 1);
			ans -= arr[n][i];
			visited[i] = false;
		}
	}
}
int main() {
	int testcase; cin >> testcase;
	while (testcase--) {
		for (int i = 0; i < 11; i++) 
			for (int j = 0; j < 11; j++) 
				cin >> arr[i][j];
		//cout <<DFS(0)<<endl;
		DFS(0);

		cout << finalans << endl;
		finalans = 0;
	}
	return 0;
}