//#include <iostream>
//#include <string>
//#include <algorithm>
//#define endl "\n"
//using namespace std;
//int N ,K;
//
//int main() {
//	cin >> N >> K;
//	
//	int cnt = 0;
//
//	for (int hour = 0; hour <= N; hour++) {
//		if (hour % 10 == K || hour / 10 == K) {
//			cnt += 3600;
//			// �ð��� 3600�ʴϱ�
//			// �� �ڸ��� �Ķ���Ͱ� ������
//			//3600�� ī����
//		}
//		else {// hour���� �Ѿ����
//			for (int min = 0; min < 60; min++) {
//				if (min % 10 == K || min / 10 == K) {
//					cnt += 60; // �̹��� minute�� �ɸ��� 60����
//				}// 1�п� 60�ʴϱ�
//				else {
//					for (int sec = 0; sec < 60; sec++) {
//						if (sec % 10 == K || sec / 10 == K) {
//							cnt++; // ��� 1�ʴϱ� �׳� ī��Ʈ++
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << cnt << endl; // �� ����ع���
//	return 0;
//}
//
///*
//#include<stdio.h>
//int main(void)
//{
//	int number=7;
//	char charValue=number+'0';
//	printf("The value is :%c",charValue);
//	return 0;
//} -> converting int to char only bet 0 ~9
//
//*/


// ���� Ž���� �ݺ��� �Һ���
/*
�ͳ����� �̿��� �˰����� ���缺 ���� ->	�ݺ��� �Һ���( loop invariant ) 
�ݺ����� ������ �� �� ����� �� ���� �߰� ����� �츮�� ���ϴ� ������ ���� �� ���� �� �ִ��� ����ϴ� ������.
�ݺ����� �������� ������ ��� �ϱ� ���ؼ��� �׻� �� ���� ������ �ʰ� �����ؾ� ��.
*/
#include <iostream>
#include <vector>
using namespace std;

int binsearch(const vector<int>&A, int x) {
	// A�� ������������ ���ĵǾ��ִ�. 
// ��� : A[i-1] < x <=A[i]�� return
	 // 
	int n = A.size(); // vector�� 1���� ���°� ����?
	int low = -1, high = n;
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		if (A[mid] < x) low = mid;
		else high = mid;

	}
	return high;
}
int arr[1000001];
int sum[1000001];

/* The reason why you learn segment tree is
 �迭�� ���� ���� ���ϰ�, �� ���̿��� �� ������� ���� ���ؾ� �ϴ»�Ȳ�̸�,
 segment tree��ŭ ������ ����. ���� ������ ���� arr�� �ִ°Ŵ� O(1)�̱� ������
 ���� ���Ҷ� �Ź� O(N)��ŭ ��������ؼ� ������ ����
*/
void alpha_to_beta(int a, int b) {
	arr[a] = b;
}
void Sum_gamma_to_delta(int a, int b) {

}
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int NUM = M + K;
	while (NUM--) {
		int check;
		cin >> check;
		if (check == 1) {
			int alpha, tobeta;
			cin >> alpha >> tobeta;
			arr[alpha] = tobeta;
			//alpha_to_beta(alpha, tobeta);
		}
		if (check == 2) {
			int gamma, delta,ans=0;
			cin >> gamma >> delta;
			for (int k = gamma; k <= delta; k++) {
				ans += arr[k];
			}
			cout << ans << endl;
			//Sum_gamma_to_delta(gamma, delta);
		}
	}


	return 0;
}