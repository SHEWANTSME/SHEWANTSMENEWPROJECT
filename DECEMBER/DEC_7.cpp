//#include <iostream>
//// 음식 메뉴 정하기
//#include<vector>
//#include <algorithm>
//#define INF 987654321;
//void canEat( const vector<int>&menu)
//{
//	return false;
//}
//int M = 30;
//
//int selectMenu(vector<int>&menu, int food) {
//	if (food == M) {
//		if (canEat(menu)) return menu.size();
//		return INF;
//	}
//	int ret = selectMenu(menu, food + 1);
//	menu.push_back(food);
//	ret = min(ret, selectMenu(menu, food + 1));
//	menu.pop_back();
//	return ret;
//}
//int main() {
//	vector<int>menu;
//	menu.push_back(10);
//	menu.push_back(20);
//	selectMenu(menu, 3);
//	selectMenu(v, 3);
//	
//	return 0;
//}
//
//
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321;
#define endl "\n"
using namespace std;

vector<int> factor(int n) {
	if (n == 1) return vector<int>(1, 1);
	vector<int > ans;
	for (int i = 2; n > 1; i++) {
		while (n%i == 0) {
			n = n / i;
			ans.push_back(i);
		}
		return ans;
	}
}
void selectionSort(vector<int>&a) {
	for (int i = 0; i < a.size(); i++) {
		int minIndex = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[minIndex] > a[j]) minIndex = j;
			swap(a[i], a[minIndex]);
		}
	}
}
void InsertionSort(vector<int>&a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
		}
	}
}
const int MIN = numeric_limits<int>::lowest(); // numeric_limits의 min은 float나 double같이 부동소수점 있으면 골치아파짐

int inefficientMaxSum(const vector<int>&e) {
	// 무지성 for문 
	int N = e.size(), ans = MIN;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) { sum += e[k]; }
            ans = max(ans, sum);
		}		
	}
	// this function is O(N^3)
	return ans;
}
int betterMaxSum(const vector<int>&e) {
	// 조금 더 나은 방법 O(N^2)
	int N = e.size(), ans = MIN;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum = sum + e[j];
			ans = max(ans, sum);
		}
	}
	return ans;
}
int fastMaxSum(const vector<int>&e, int low, int high) {
	// 분할정복 사용 O(NlogN)
	cout << "현재 상태는 FMS (" << low << ',' << high << ")" << endl;
	if (low == high) return e[low] or e[high]; // 구간 길이가 1 일때 걍 그 원소 리턴
	int mid = (low + high) / 2; // 배열 반띵을 위한 mid
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >=low; i--) { // 반띵 왼쪽부분  for (int i = low; i <=mid; i++)이랑 same
		sum += e[i];  // bettermaxsum이랑 다른게, 일단 반띵의 sum중에
		left = max(left, sum); // 반띵의 sum중에 max가 left에 담기게 되고
	}
	sum = 0; // sum은 다시 써야되니까 0으로 초기화 해주고
	for (int j = mid + 1; j <= high; j++) { // 나머지 오른쪽 반띵도 마찬가지로
		sum += e[j];
		right = max(right, sum); // 나머지 오른쪽 반띵의 sum의 max 가 right에 담기게 됨
	}
	
	/*int realmax = max(left, right);// 지금 내가 하려고 했던 이것들이 왜 안되냐? 를 고찰해 보자면
	return realmax; // 가장 중요한건 , 내가 지금 이 fastMaxSum을 이번 단계로만 끝내려는게 아니고,
	결국 범위들을 잘게 쪼개서 나오는 max들중에 가장 큰 놈을 찾아서 리턴하는게 목표임
	근데 지금 이 주석처리 되어있는놈들을 보면 , 절대 범위들을 잘게 쪼갤 수가 없음
	재귀적으로 이 함수를 쪼갤 방법을 생각해보면 , 지금 이상태에서의 left랑 right의 max보다는
	다 쪼개진 놈들의 max를 따로 변수를 만들어서 그 변수와 지금 left와 right의 max를 반환해야 최종적인
	max가 나온다는 사실은 자명함. 고로, 밑에방법처럼 풀이를 해야 마땅하다.
	int realsingle = max(fastMaxSum(e, low, mid), );*/
	int ALPHA = fastMaxSum(e, low, mid);
	int BETA = fastMaxSum(e, mid + 1, high);
	int single = max(ALPHA, BETA);	
	int realreal = max(single, left + right);
	return realreal;
	////int single = max(fastMaxSum(e, low, mid), fastMaxSum(e, mid + 1, high));
	//int what = max(left, right);
	////return max(single, left+right);
	//왜 return max(single, left+right)인가에 대해 20분정도 고민해본결과, 다음과 같다.
	/*
	다 하나씩 찍어보면 , 기저상태일때 리턴되는애들은 그 배열의 값임. 걔네들부터 일단 더해놔야 최종적으로 LEFT+RIGHT의 값을
	알 수 있음. 
	현재 상태는 FMS (0,7)
	현재 상태는 FMS (0,3)
	현재 상태는 FMS (0,1)
	현재 상태는 FMS (0,0)
	현재 상태는 FMS (1,1)
	현재 상태는 FMS (2,3)
	현재 상태는 FMS (2,2)
	현재 상태는 FMS (3,3)
	현재 상태는 FMS (4,7)
	현재 상태는 FMS (4,5)
	현재 상태는 FMS (4,4)
	현재 상태는 FMS (5,5)
	현재 상태는 FMS (6,7)
	현재 상태는 FMS (6,6)
	현재 상태는 FMS (7,7)
	fast : 10
	
	*/

}
int mywayMaxSum(const vector<int>&e) {
	//O(N)
	int N = e.size(), ans = MIN;
	vector<int>dp(N);
	dp[0] = e[0];
	dp[1] = (e[0] < 0) ? e[1] : e[1] + e[0];	
	for (int i = 2; i < N; i++) {
		//dp[i] = max(dp[i - 1],-1000) + e[i]; // 이게 원래 내가 짯던거 dp[i] = dp[i-1] + e[i]는 
		//ans = max(ans, dp[i]);
		dp[i] = dp[i - 1] + e[i];// 맞자나 ㅂㄷㅂㄷ
		ans = max(ans, dp[i]);
	}
	return ans;
}



int main(){
	vector<int>v = { -7, 4 ,-3, 6, 3, -8, 3, 4 };
	cout << "이건 1부터 측정하는 사이즈"<<v.size() << endl;
	cout << "이건 사이즈 오브"<<sizeof(v) << endl; // 왜 항상 16이지? -> 정확히 왜 이런지는 모르겠당 윈도우 환경에따라 다른가?
	cout << sizeof(int)<<endl;
	cout << "내가 짠 코드의 답 : " << mywayMaxSum(v) << endl;
	cout << "inefficient : " << inefficientMaxSum(v) << endl;
	cout << "better : " << betterMaxSum(v) << endl;
	cout << "fast : " << fastMaxSum(v, 0, v.size()-1 );
	// v.size는 1부터 세기 때문에 인덱스를 참조하는거면 1을 빼는것이고
	//sizeof는 해당 자료형의 size를 나타내는거임!!
	

	return 0;
}
