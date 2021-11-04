//#include<iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int abst(int x) {
//	 x = (x > 0) ? x : -x;
//	 return x;
//}
//int main() {
//	int n,now,cnt=0,pre,alpha=1;
//	cin >> n;
//	vector <int> v(n);
//	cin >> pre; // 처음원소
//	v[0] = 0;
//	for (int i = 1; i < n; i++) {
//		
//		cin >> now; // 나머지 원소
//		alpha = abst(pre - now);
//		if (alpha < n && alpha > 0 && v[alpha] == 0) { v[alpha] = 1; }
//		else { printf("NO\n");  exit(0); }
//		pre = now;
//	}
//	printf("YES\n");
//	//pre = v[0];
//	//
//	//for (int i = 1; i < n-1; i++) {
//	//	now = v[i];
//	//	if(abst(pre-now) <n && abst(pre-now)>0) 
//	//	if (now >= pre) { cnt++; alpha = max(cnt, alpha); }
//	//	else { cnt = 1; }
//	//	pre = now;
//	//}
//	//cout << alpha << endl;
//	return 0;
//}


//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main() {
//	int n,k=1,cnt =1;
//	scanf_s("%d", &n);
//	vector<int>v(n);
//	vector<int> v2(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//		v2[i] = 1;
//	}
//	
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (v[i] > v[j]) v2[j]++;
//			if (v[i] < v[j]) v2[i]++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout <<" " <<v2[i];
//	}
//	return 0;
//}
// 백준 골드,, 찍고 어디분야를 나아가고싶냐를 궁리해야할듯 파이썬을 다 봐야하나,,
// ㅅㅂ 존나 머리아프네 ,, ㅅ,,ㅅ,ㄷ,ㅅ,ㄷ,,,ㅅ


//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	vector <int > v(n);
//	vector <int> v2(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//		v2[i] = 1;
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j <i; j++) {
//			if (v[i] < v[j]) v2[i]++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << v2[i] << endl;
//	}
//
//	return 0;
//}


#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

//factorial fucking hard
int result[1000] = { 0, };
int cnt = 0;
void retry(int i);
void soinsu(int n) {
	
	int i = 2;
	int t = n;
	while (i < t ) {
		if (t % i == 0) {
			//result[t / i]++;
			
			if ((t/i)==2||(t / i) == 3 || (t / i) == 5 || (t / i) == 7) {
				result[t / i]++;
			}
			else if((t / i) != 2 || (t / i) != 3 || (t / i) != 5 || (t / i) != 7) { soinsu((t / i)); cnt += 1; }
			else if (cnt==0) {
				result[i]++;
				t--;
				i = 2;
			}
			
						
		}
		else i++;		
	}
	
	if (t==i) {
		retry(i);
	}
}
void retry(int i) {
	result[i]++;
	int k = i - 1;
	i = 2;
	if (k != 2 || k != 3 || k != 5 || k!= 7) soinsu(k);
}

int main() {
	int n;
	cin >> n;
	soinsu(n); // 10을 찍으면 
	cout << result[5] << endl; // 2
	cout << result[2] << endl; // 8
	//cout << std::min(result[5], result[2]) << endl;
}
//
//소인수분해를 할 줄 알면은 가능하다 이말이야..
//
//x *10 *10 -> 뒤에 0 두개 생김
//곱하기 10이 몇개냐 있냐를 찾으면 됨 -> 소인수 분해를 해서 각 숫자에 
//2랑 5가 몇개 있냐를 찾으면 해결따링