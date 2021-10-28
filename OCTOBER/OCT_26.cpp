//#include <iostream>
//#include <vector>
//using namespace std;
//
//void findcoin(int a, vector<int> &v,int cnt) {
//	int alpha = a / v.back();
//	if (a - (alpha*v.back()) == 0) { cnt = cnt + alpha; }// { cout << alpha << endl; }
//	else {
//		a = a - (alpha*v.back());
//		cnt = cnt + alpha;
//		while (v.back() > a) {
//			v.pop_back();
//		}
//		findcoin(a, v, cnt);
//	}
//
//	cout << cnt << endl;
//	exit(0);
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	while (v.back() > k) {
//		v.pop_back();
//	}
//	findcoin(k, v, 0);
//	
//}
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin >> str;

	int sum = 0;int num = 0;int check = 0;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '-' || str[i] == '+'){
			if (check!=0)sum -= num;  // '-' 가 한번이라도 나온 후에는 전부 빼주기
			else sum += num;        // '-' 가 나오기 전까지는 더해주기

			num = 0;       //num수를 다시 리셋
			if (str[i] == '-')check = 1;  //-가 나오면 flag를 true로 바꿔줌
		}
		else{
			//숫자가 연속해서 나오는동안은 한 수로 붙이기
			num = num*10;
			num += str[i] - 48;  // 아스키코드 이용
		}
	}

	//마지막남은 숫자도 처리해주어야 한다
	if (check!=0)sum -= num;
	else sum += num;
	printf("%d ", sum);

	return 0;
}