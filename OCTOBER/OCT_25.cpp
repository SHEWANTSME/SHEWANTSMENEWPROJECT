//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, s;
//int arr[100000];
//int main(void) {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//
//	int left = 0, right = 0, sum = 0, res = n;
//	bool existence = 0;
//	// N =10 S = 100
//	// 10 20 30 11 12 17 20 23 10 5
//
//	while (1) { // 일단 무조건 실행
//		if (sum >= s && s!=0) {  // RIGHT이 6일때 여기 실행이네 딱 100이니까 // 다시 일로옴
//			existence = 1; // 그래 // ㅇㅇ
//			res = min(res, right - left); // 나머지는 = 나머지랑, 6-0 중에 작은거 -> MIN(10,6) -> RES = 6; // RES = 6,
//			sum -= arr[left++];// SUM = SUM-ARR[0] -> 100-10 = 90 LEFT 1
//		} // 다시 일로 올땐 90이 SUM이라 PASS
//		else if (right == n) break;// 1 !=10
//		else sum += arr[right++]; // 처음엔 여기로 오겠지  SUM = SUM+ARR[0] 이후 1로 변경  아직 SUM=10
//		// 다시여기로 SUM =10+20 = 30 30+30 = 60 60+11 = 71 71+12 = 83 + 17 = 100임 RIGHT =6// SUM = SUM+ARR[7]=110
//	}
//	if (existence!=0) cout << res;
//	else cout << 0;
//	return 0;
//}

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
	int num,sum=0;
	cin >> num;
	vector<int>v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	while (v.size()) {
		for (auto &element : v) {
			sum = sum + element;
			
		}v.pop_back();
	}	
	cout << sum << endl;
	


}