	//while (n != 0) {
	//	string s;
	//	cin >> s;
	//	if (s == "push") {
	//		int ss;
	//		cin >> ss;
	//		push(ss);
	//	}
	//	else if (s == "pop") {
	//		pop();
	//	}
	//	else if (s == "empty") {
	//		empty();
	//	}
	//	else if (s == "top") {
	//		top();
	//	}
	//	else if (s == "size") {
	//		size();
	//	}
	//	n--;
	//}


//
//#include <iostream>
//using namespace std;
//
//#define MAX_X 100
//#define MAX_Y 100
//#define MIN_X 0
//#define MIN_Y 0
//class Point {
//private:
//	int m_x, m_y;
//public:
//	void setx(int x) {
//		if (MAX_X < x) x = MAX_X;
//		if (MIN_X > x)x = MIN_X;
//		m_x = x;
//	}
//	void sety(int y); // ���� class���ο� �ϰ� ������ Ŭ���� ������ ���°� ����
//	int getx() {
//		return m_x;
//	}
//	
//	int gety() { // �̷��� �ϴ°Ͱ� �ٸ����� ����
//		return m_y;
//	}
//	void print() { // �ٵ� ���� print�� Ŭ���� ���ο� �ְ� get�� ���� ��Ȳ�ε�
//		// get�� Ŭ���� �ۿ��� ȣ��Ǵ� ��Ȳ�̸� error!!
//		cout << "Point = (" << Point::getx() << "," << gety() << ")" << endl;
//	}
//};
//void Point::sety(int y) {
//	if (MAX_Y < y) y = MAX_Y;
//	if (MIN_Y > y)y = MIN_Y;
//	m_y = y;
//}
//
//
//int max(int a, int b) {
//	if (a > b) return a;
//	else return b;
//}
//template<class T>
//T maxx(T a, T b) {
//	if (a > b) return a;
//	else return b;
//}
//template <typename T>
//T sum(T data[], int datacount) {
//	T s = 0;
//	for (int i = 0; i < datacount; i++) {
//		s += data[i];
//	}
//	return s;
//}
//template <typename w , class s>
// function(w a, s b) {
//
//}
//int main() {
//	cout << max(10, 4) << endl;
//	cout << maxx(11.2, 14.3) << endl;
//	cout << maxx('k', 's');
//	int data[] = { 10,30,20 };
//	cout << "sum(data,3)" << sum(data, 3) << endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
////
////
////int main() {
////
////	Point pt;
////	pt.setx(100);
////	pt.sety(-10);
////	pt.print();
////	return 0;
////}



#include <iostream>
#include <vector>
using namespace std;

struct stack {
	int top;
	int data[10000];
};
void initialize(stack stk) {
	stk->top = -1;
}