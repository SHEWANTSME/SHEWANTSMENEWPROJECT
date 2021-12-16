//#include<iostream>
//#include <algorithm>
//#define endl "\n"
//using namespace std;
//int dp[101];
//int save[101];
//int check[101];
//int main() {
//	int c, n; cin >> c >> n;
//	//int k = n;
//	while (n--) {
//		int money, cost;
//		cin >> money >> cost;
//		if (save[money] == 0) {
//			save[money] = cost;
//		}
//		else{
//			save[money] = max(save[money], cost);
//		}
//		
//	//	dp[money][cost] = 1;
//	}
//	if (save[1] == 0) dp[1] = 0;
//	if (save[1] != 0) dp[1] = save[1];
//	/*if (k == 1 ) {
//		cout << dp[1] << endl;
//		exit(0);
//	}*/
//	//if (k != 1) {
//		dp[2] = 2*dp[1];
//		if (save[2]) dp[2] = max(dp[2], save[2]);
//		//if (k == 2) { cout << dp[2] << endl; exit(0); }
//		//if (k != 2) {
//		//int ans = 0;
//			for (int i = 3; i <= c; i++) {
//				for (int j = 1; j < i; j++) {
//					check[i] = dp[1]+dp[i-1];
//					check[i] = dp[j] + dp[i - j];
//					/*if (j <= i / 2) {
//						dp[i] = max(dp[i - 1], dp[j] + dp[i - j]);
//						cout << dp[i] << endl;
//					}
//					*/
//					
//				}
//				for (int i = 3; i <= c; i++) {
//					dp[i] = max(check[i], -1);
//					cout << dp[i] << endl;
//				}
//				//dp[i] =  dp[i - 1] + dp[1];
//				if (save[i]) {
//					dp[i] = max(dp[i], save[i]);
//				}
//				cout << "dp[" <<i<<"]"<< dp[i] << endl;
//			/*	if (dp[i] >= c) {
//					cout << dp[i] << endl;
//					exit(0);
//				}*/
//	
//			}
//			//cout << dp[c] << endl;
//		//}
//		
//	//}
//	
//	return 0;
//}

#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int dp[101];
int save[101];
bool check = false;
int main() {
	int n, k;
	cin >> n >> k;
	while (n--) {
		int num;
		cin >> num;
		save[num] = 1;
	}
	int t=0, cnt = 0; pair<int, int>a; int ans = 0;
	for (int i = k; i >= 1; i--) {
		if (save[i]) { 
			cnt++;
			if (cnt == 1) {
				a.first = cnt;
				a.second = i;
			}	

			dp[i] = save[i]; 
			t=i; 			
		}
	}
	dp[t] = save[t];
	for (int i = t; i <= k; i++) {
		if (i <= a.second) {
			if (dp[i] == 0) dp[i] = dp[i - 1] + 1;
			for (int j = t; j < i; j++) {

			}
			
		}
		else {
			for (int j = t; j < i; j++) {
				ans = min(100000, dp[j] + dp[i - j]);
			}
			dp[i] = ans;
		}
		cout << "dp[i]"<<dp[i] << endl;
	}
	//cout << dp[k] << endl;
	return 0;
}