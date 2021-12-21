//#include <iostream>
//*
//[captures] (parameters) -> return type{body}
//
//captures : 콤마로  구분된 캡쳐들이 들어감
//parameters : 함수의 인자들이 들어감
//  return type : 함수의 반환형
//  body : 함수 몸통
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
//	for_each(v.begin(), v.end(), [=](int &k) {// 전역변수는
//		// 캡쳐할때 & ,=만 써야됨 
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

captures : 콤마로  구분된 캡쳐들이 들어감
parameters : 함수의 인자들이 들어감
  return type : 함수의 반환형
  body : 함수 몸통
*/
int main() {
	auto func = [](const int& i) -> void {cout << "hello world!" << endl; };
	// 굳이 auto func = 을 안붙여도 사용가능한 lambda
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
	//auto func2 = [](int val)-> void { cout << val << endl; }; void일땐 안써도됨

	for_each(v.begin(), v.end(), func2);
	// for_each(v.begin(), v.end() , [](int val){cout << val << endl; }); 가능
	cout << []() -> int {return 1; }() << endl;

	function<void(int)> func3 = func2;
	func3(123);
	//#include <functional> 써서
	// function<함수타입(함수type의인자)> ~~ 하면 됨
	function<void()> func4 = bind(func3, 456); // func3가 int만 받고
	// func4가 bind로만 묶여있으니까 func4자체는 void임
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
std::bind(함수 주소, 함수인자1, 함수인자2, 함수인자3, ...)

함수인자에 초기값을 설정한수 있고

bind로 생성한 함수의 인자로 받을 것이면

std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, ... 등을 새로운 함수 인자와 맵핑 시킬수있다.



void Func( int iA, float fB, bool bC );

라는 3개의 인자를 가지는 함수가있다면



auto funcA = std::bind( Func, 10, 2.0f, true );

funcA();

다음과 같이 단일 함수로 사용가능하고



그중 float 인자값을 새로운 함수의 인자로 받으려면

auto funcB = std::bind( Func, 10, std::placeholders::_1, true );

funcB( 2.0f );



처음인자는 float 두번쩨 인자는 int를 받고 싶으면

auto funcC = std::bind( Func, std::placeholders::_2, std::placeholders::_1, true );

funcC( 2.0f, 10 );



3번쩨 인자에 bool 값을 받고 싶으면

auto funcD = std::bind( Func, std::placeholders::_2, std::placeholders::_1, std::placeholders::_3 );

funcD( 2.0f, 10, true );
*/