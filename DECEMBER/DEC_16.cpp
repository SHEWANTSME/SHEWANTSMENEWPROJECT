//#include <iostream>
//*
//[captures] (parameters) -> return type{body}
//
//captures : �޸���  ���е� ĸ�ĵ��� ��
//parameters : �Լ��� ���ڵ��� ��
//  return type : �Լ��� ��ȯ��
//  body : �Լ� ����
//*/
//#include<vector>
//#include<algorithm>
//#include <string>
//using namespace std;
//int summ = 0;
//class Person {
//public:
//	Person(string name) : name(name) {}
//	void introduce() {
//		[this]() {cout << "my name is " << name << endl; }();
//	}
//private:
//	string name;
//};
//
//vector<int>v = { 1,2,3,4,5 };
//int main() {
//	int sum = 0;
//	for_each(v.begin(), v.end(), [&sum](int&numbers) {
//		sum += numbers;
//	});
//	for_each(v.begin(), v.end(), [=](int &k) {// ����������
//		// ĸ���Ҷ� & ,=�� ��ߵ� 
//		summ += k;
//	});
//	cout << summ << endl;
//	cout << sum << endl;
//
//	Person* ktl = new Person("kaete");
//	ktl->introduce();
//	return 0;
//}

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void goodbye(const string &s) {
	cout << "Goodbye" << s << endl;
}
class Object {
public : 
	void hello(const string &s) {
		cout << "Hello " << s << endl;
	}
};
/*
[captures] (parameters) -> return type{body}

captures : �޸���  ���е� ĸ�ĵ��� ��
parameters : �Լ��� ���ڵ��� ��
  return type : �Լ��� ��ȯ��
  body : �Լ� ����
*/
int main() {
	auto func = [](const int& i) -> void {cout << "hello world!" << endl; };
	// ���� auto func = �� �Ⱥٿ��� ��밡���� lambda
	//[](const int& i) -> void {cout << "hello world!" << endl; }(1234);
	func(123);
	
	{
		string name = "john";
		[&]() {cout << name << endl; }();
	}
	vector<int>v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) { cout << val << endl; };
	//auto func2 = [](int val)-> void { cout << val << endl; }; void�϶� �Ƚᵵ��

	for_each(v.begin(), v.end(), func2);
	// for_each(v.begin(), v.end() , [](int val){cout << val << endl; }); ����
	cout << []() -> int {return 1; }() << endl;

	function<void(int)> func3 = func2;
	func3(123);
	//#include <functional> �Ἥ
	// function<�Լ�Ÿ��(�Լ�type������)> ~~ �ϸ� ��
	function<void()> func4 = bind(func3, 456); // func3�� int�� �ް�
	// func4�� bind�θ� ���������ϱ� func4��ü�� void��
	func4();
	{
		Object instance;
		auto f = bind(&Object::hello, &instance, std::placeholders::_1);
		f(string("World"));
		// can be used as f("World");
		auto f2 = bind(&goodbye, std::placeholders::_1);
		f2(string("World"));
	}

	return 0;
}
/*
hello world!
john
1
2
1
123
456
Hello World
GoodbyeWorld
*/
/*
std::bind(�Լ� �ּ�, �Լ�����1, �Լ�����2, �Լ�����3, ...)

�Լ����ڿ� �ʱⰪ�� �����Ѽ� �ְ�

bind�� ������ �Լ��� ���ڷ� ���� ���̸�

std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, ... ���� ���ο� �Լ� ���ڿ� ���� ��ų���ִ�.



void Func( int iA, float fB, bool bC );

��� 3���� ���ڸ� ������ �Լ����ִٸ�



auto funcA = std::bind( Func, 10, 2.0f, true );

funcA();

������ ���� ���� �Լ��� ��밡���ϰ�



���� float ���ڰ��� ���ο� �Լ��� ���ڷ� ��������

auto funcB = std::bind( Func, 10, std::placeholders::_1, true );

funcB( 2.0f );



ó�����ڴ� float �ι��� ���ڴ� int�� �ް� ������

auto funcC = std::bind( Func, std::placeholders::_2, std::placeholders::_1, true );

funcC( 2.0f, 10 );



3���� ���ڿ� bool ���� �ް� ������

auto funcD = std::bind( Func, std::placeholders::_2, std::placeholders::_1, std::placeholders::_3 );

funcD( 2.0f, 10, true );
*/