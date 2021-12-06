//#include <iostream>
//#define endl "\n"
//using namespace std;
//
//int n, m;
//int arr[9]; //숫자담는놈
//bool visited[9]; // 체크하는놈
//void DFS(int cnt){
//	if (cnt == m)	{
//		for (int i = 0; i < m; i++)	cout << arr[i] << " ";
//			cout << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++){// 처음에 cnt가 0 이니까
//		if (visited[i]==NULL){ // 당근 visited도 0
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
//	// 위의 예제에서 Local() 함수안의 매개변수 n는 인수로 변수 nk의 값을 전달받습니다.
////	따라서 함수 내에서 매개변수 n의 값을 아무리 변경하더라도 원래 인수로 전달된 변수 nk의 값은 절대 변경되지 않습니다.
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
//	cout << Local(10) << endl; // 그래서 이렇게 보통 출력하지.  아니면
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
int  visited[11];  // 항상 dfs는 visited가 필요함!!!!!!!
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