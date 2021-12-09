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
//			// 시간은 3600초니까
//			// 각 자리에 파라미터가 있으면
//			//3600초 카운팅
//		}
//		else {// hour에는 넘어갔지만
//			for (int min = 0; min < 60; min++) {
//				if (min % 10 == K || min / 10 == K) {
//					cnt += 60; // 이번엔 minute에 걸리면 60이지
//				}// 1분에 60초니까
//				else {
//					for (int sec = 0; sec < 60; sec++) {
//						if (sec % 10 == K || sec / 10 == K) {
//							cnt++; // 얘는 1초니까 그냥 카운트++
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << cnt << endl; // 싹 출력해버렷
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


// 이진 탐색과 반복문 불변식
/*
귀납법을 이용한 알고리즘의 정당성 증명 ->	반복문 불변식( loop invariant ) 
반복문의 내용이 한 번 실행될 때 마다 중간 결과가 우리가 원하는 답으로 가는 길 위에 잘 있는지 명시하는 조건임.
반복문이 마지막에 정답을 계산 하기 위해서는 항상 이 식이 변하지 않고 성립해야 함.
*/
#include <iostream>
#include <vector>
using namespace std;

int binsearch(const vector<int>&A, int x) {
	// A는 오름차순으로 정렬되어있다. 
// 결과 : A[i-1] < x <=A[i]를 return
	 // 
	int n = A.size(); // vector는 1부터 세는거 알지?
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
 배열의 값이 많이 변하고, 그 사이에서 의 관계들을 자주 구해야 하는상황이면,
 segment tree만큼 좋은게 없다. 지금 문제도 보면 arr를 넣는거는 O(1)이긴 하지만
 합을 구할때 매번 O(N)만큼 구해줘야해서 문제가 생김
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