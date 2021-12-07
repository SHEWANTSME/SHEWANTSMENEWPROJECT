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

// what the fuck is wrong with it?
//왜 씨발 됐다가 안됐다가 하는거-> 니가 namespace 정의를 안했자나 빡대갈아
void Init (vector<int>&vec2) {
	// 첫번째 방법
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);
	for (auto &e : vec2) {
		cout <<"처음"<< e << endl;
	 }
	vec2.clear();
	int p = 3;
	// 2번째 방법
	vector<int>vec3(p, 10); // 1st인자-> 사이즈, 2nd인자 -> 숫자 // 10 10 10 찍힘
	for (auto &e : vec3) {
		cout <<"두번째"<< e << endl;
	}
	vec3.clear();
	//3번째방법
	vector<int>vec4{ 10,20,30,40,50 };
	for (auto&e : vec4) {
		cout << "3번째"<<e << endl;
	}
	vec4.clear();
	//4번째 방법
	int arr[] = { 10,20,30, };
	//int arr2[]({ 3,2,1 }); 이렇게 하고싶으면 명확하게 arrsize도 써줘야함 arr2[3]이렇게

	int num = sizeof(arr) / sizeof(int);

	vector<int>vec5(arr, arr +num);
	for (auto&e : vec5) {
		cout << "4번째"<<e << endl;
	}
	vec5.clear();
	//5번째 방법
	vector<int >vec6{ 10,20,30 };
	vector<int> vex2(vec6.begin(), vec6.end());
	for (auto&e : vex2) {
		cout << "5번째"<<e << endl;
	}
	vec6.clear();
	vex2.clear();
	// 마지막방법 initializing all elements with a particular value
	vector<int> vec7(10);
	int value = 7;
	fill(vec7.begin(), vec7.end(), value);
	for(auto&e : vec7) {
		cout <<"last"<< e << endl;
	}
}

int main(){
	vector<int>v;
	Init(v);


	return 0;
}
