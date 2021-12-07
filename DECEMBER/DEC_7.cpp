//#include <iostream>
//// ���� �޴� ���ϱ�
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
const int MIN = numeric_limits<int>::lowest(); // numeric_limits�� min�� float�� double���� �ε��Ҽ��� ������ ��ġ������

int inefficientMaxSum(const vector<int>&e) {
	// ������ for�� 
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
	// ���� �� ���� ��� O(N^2)
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
	// �������� ��� O(NlogN)
	cout << "���� ���´� FMS (" << low << ',' << high << ")" << endl;
	if (low == high) return e[low] or e[high]; // ���� ���̰� 1 �϶� �� �� ���� ����
	int mid = (low + high) / 2; // �迭 �ݶ��� ���� mid
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >=low; i--) { // �ݶ� ���ʺκ�  for (int i = low; i <=mid; i++)�̶� same
		sum += e[i];  // bettermaxsum�̶� �ٸ���, �ϴ� �ݶ��� sum�߿�
		left = max(left, sum); // �ݶ��� sum�߿� max�� left�� ���� �ǰ�
	}
	sum = 0; // sum�� �ٽ� ��ߵǴϱ� 0���� �ʱ�ȭ ���ְ�
	for (int j = mid + 1; j <= high; j++) { // ������ ������ �ݶ� ����������
		sum += e[j];
		right = max(right, sum); // ������ ������ �ݶ��� sum�� max �� right�� ���� ��
	}
	
	/*int realmax = max(left, right);// ���� ���� �Ϸ��� �ߴ� �̰͵��� �� �ȵǳ�? �� ������ ���ڸ�
	return realmax; // ���� �߿��Ѱ� , ���� ���� �� fastMaxSum�� �̹� �ܰ�θ� �������°� �ƴϰ�,
	�ᱹ �������� �߰� �ɰ��� ������ max���߿� ���� ū ���� ã�Ƽ� �����ϴ°� ��ǥ��
	�ٵ� ���� �� �ּ�ó�� �Ǿ��ִ³���� ���� , ���� �������� �߰� �ɰ� ���� ����
	��������� �� �Լ��� �ɰ� ����� �����غ��� , ���� �̻��¿����� left�� right�� max���ٴ�
	�� �ɰ��� ����� max�� ���� ������ ���� �� ������ ���� left�� right�� max�� ��ȯ�ؾ� ��������
	max�� ���´ٴ� ����� �ڸ���. ���, �ؿ����ó�� Ǯ�̸� �ؾ� �����ϴ�.
	int realsingle = max(fastMaxSum(e, low, mid), );*/
	int ALPHA = fastMaxSum(e, low, mid);
	int BETA = fastMaxSum(e, mid + 1, high);
	int single = max(ALPHA, BETA);	
	int realreal = max(single, left + right);
	return realreal;
	////int single = max(fastMaxSum(e, low, mid), fastMaxSum(e, mid + 1, high));
	//int what = max(left, right);
	////return max(single, left+right);
	//�� return max(single, left+right)�ΰ��� ���� 20������ ����غ����, ������ ����.
	/*
	�� �ϳ��� ���� , ���������϶� ���ϵǴ¾ֵ��� �� �迭�� ����. �³׵���� �ϴ� ���س��� ���������� LEFT+RIGHT�� ����
	�� �� ����. 
	���� ���´� FMS (0,7)
	���� ���´� FMS (0,3)
	���� ���´� FMS (0,1)
	���� ���´� FMS (0,0)
	���� ���´� FMS (1,1)
	���� ���´� FMS (2,3)
	���� ���´� FMS (2,2)
	���� ���´� FMS (3,3)
	���� ���´� FMS (4,7)
	���� ���´� FMS (4,5)
	���� ���´� FMS (4,4)
	���� ���´� FMS (5,5)
	���� ���´� FMS (6,7)
	���� ���´� FMS (6,6)
	���� ���´� FMS (7,7)
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
		//dp[i] = max(dp[i - 1],-1000) + e[i]; // �̰� ���� ���� ­���� dp[i] = dp[i-1] + e[i]�� 
		//ans = max(ans, dp[i]);
		dp[i] = dp[i - 1] + e[i];// ���ڳ� ��������
		ans = max(ans, dp[i]);
	}
	return ans;
}



int main(){
	vector<int>v = { -7, 4 ,-3, 6, 3, -8, 3, 4 };
	cout << "�̰� 1���� �����ϴ� ������"<<v.size() << endl;
	cout << "�̰� ������ ����"<<sizeof(v) << endl; // �� �׻� 16����? -> ��Ȯ�� �� �̷����� �𸣰ڴ� ������ ȯ�濡���� �ٸ���?
	cout << sizeof(int)<<endl;
	cout << "���� § �ڵ��� �� : " << mywayMaxSum(v) << endl;
	cout << "inefficient : " << inefficientMaxSum(v) << endl;
	cout << "better : " << betterMaxSum(v) << endl;
	cout << "fast : " << fastMaxSum(v, 0, v.size()-1 );
	// v.size�� 1���� ���� ������ �ε����� �����ϴ°Ÿ� 1�� ���°��̰�
	//sizeof�� �ش� �ڷ����� size�� ��Ÿ���°���!!
	

	return 0;
}
