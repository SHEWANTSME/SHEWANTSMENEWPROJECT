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
			if (check!=0)sum -= num;  // '-' �� �ѹ��̶� ���� �Ŀ��� ���� ���ֱ�
			else sum += num;        // '-' �� ������ �������� �����ֱ�

			num = 0;       //num���� �ٽ� ����
			if (str[i] == '-')check = 1;  //-�� ������ flag�� true�� �ٲ���
		}
		else{
			//���ڰ� �����ؼ� �����µ����� �� ���� ���̱�
			num = num*10;
			num += str[i] - 48;  // �ƽ�Ű�ڵ� �̿�
		}
	}

	//���������� ���ڵ� ó�����־�� �Ѵ�
	if (check!=0)sum -= num;
	else sum += num;
	printf("%d ", sum);

	return 0;
}