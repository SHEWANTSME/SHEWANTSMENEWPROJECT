#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<set>
#include <map>
#include <string>
using namespace std;


typedef struct { // 구조체는 vector<pair<int,pair<int,int>>> 이렇게 해도 되긴 함,, 보기 좀 그래서 그렇지
	int age;
	int score;
	string name;
	char kate;
}S; // for this struct's nickname
vector<S>vec; // this vector's 자료형이 S
// you can make compare func to this struct

bool comp(S a, S b) {
	if (a.score == b.score) {
		return a.age < b.age;
	}
	else a.score < b.score;
	// pair에서 first 랑 second 가 무엇을 나타냈었는지
	//생각해보면 쉬움
}


bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
	// bool이니까 true, false를 return인데 
	// 이건 그러면 오름차순이겠지?
	// 반대로 하면 내림차순 
}
vector<pair<int, int>>v;
//vector<S>vec;
int main() {
	v.push_back(make_pair(3, 4));
	v.push_back({ 1,1 }); // make_pair안써도 이렇게 해도 됨
	v.push_back({ 1,-1 });
	v.push_back({ 2,2 });
	v.push_back({ 3,3 });

	sort(v.begin(), v.end(), compare);
	for (auto &e : v) {
		cout << e.first << " " << e.second << endl;
	}
	vec.push_back({ 3, 30, "june", '0' }); 
	vec.push_back({ 2,20,"kate" ,'1'});
	vec.push_back({ 4,40,"lilly",'3' });
	sort(v.begin(), v.end(), comp);
	for (auto &e : vec) {
		cout << e.age << " " << e.kate << " " << e.name << " " << e.score << endl;
	}


	
	return 0;
}
// if you wanna make more than two elements
// try using struct!




#include <iostream>
#include <queue>
#include <algorithm>
#include<functional>
using namespace std;
// figuring out how to use priority_queue
int main() {
	priority_queue<int>pq; // when using all the variables int type
	// same as priority_queue<int , vector<int>, less<int>>
	queue<int>queue;
	pq.push(4);
	pq.push(3);
	pq.push(7);
	pq.push(1);
	pq.push(10);
	queue.push(4);
	queue.push(3);
	queue.push(7);
	queue.push(1);
	queue.push(10);
	cout << "우선순위 queue 사이즈 " << pq.size() << endl;
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << "그냥 queue size" << queue.size() << endl;
	while (!queue.empty()) {
		cout << queue.front() << endl;
		queue.pop();
	}



	return 0;
}

#include <iostream>
#include<queue>
using namespace std;
struct Student {
	int id;
	int math, eng;
	Student(int num, int m, int e) : id(num), math(m), eng(e);
	bool operator<(const Student S) const {
		return this->id > S.id;
	}
}; // what the fuck is this?

int main() {
	priority_queue<Student> pq;
	pq.push(Student(3, 100, 40));

	return 0;
}






#include <iostream>
using namespace std;

class Fraction {
public:
	int m_numerator; // these things must be initialized
	int m_denominator;
public:
	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

// 자 , 원래대로 다시 보자면
class Frac {
private:
	int m_numerator; // = 0; 이렇게 바로 해도 해도 됨
	int m_denominator;// = 1;
public:
	Frac() // this is 생성자 (constructor)
	{ 
		m_numerator = 0;
		m_denominator = 1;
		cout << "when does this work?" << endl;
	}
	Frac(const int& num_in, const int & den_in)
	{
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Frac() constructor 여러개 가능?" << endl;
	}
	Frac(const double &x, const double &y) {
		m_numerator = x + 10;
		m_denominator = y + 100;
	}
	void print() {
		cout << m_numerator << " / " << m_denominator << endl;

	}
};
int main() {


/* if you wanna do like this -> this memebers should be announced as public(which is not what I wanted
	Fraction frac;
	frac.m_numerator = 0;
	 frac.m_denominator = 1;
	 그리고 항상 이렇게 모든 멤버변수에 이럴수는 없어

	//Fraction frac{ 0,1 };
	// public 인 상태에서 이렇게 uniform initialization 해도 됨
*/
	Frac frac; // 생성자는 선언과 동시에 실행이 되는 형태임.
	// 그래서 Frac의 생성자 안에 있는 whendoesthiswork 가 먼저 실행되짐
	frac.print();
	Frac what(1, 5); // 생성자가 여러개가 가능한듯 보인다.
	what.print();
	Frac hey(3.0, 7.0); // 여러개 되넹 존나신기
	hey.print();

	/*
	when you make no any constructors
	still, there is a constructor(default constructor)
	which looks like this 
	Frac(){} -> 내가 굳이 안써도 있는 애임
	근데 생성자를 하나라도 만들었으면 더이상 default는 없어짐

	*/ 	return 0;
}


#include <iostream>
using namespace std;
class Scnd {
public:
	Scnd() {
		cout << "second class constructor() " << endl;
	}
};
class First {
	// 아무것도 안쓰면 자동 private이고
public: // 근데 생성자를 생성할때 무조건 public 안에 있어야함
	Scnd sec;

	First()
	{
			cout << "first class constructor() " << endl;
			}
};
int main() {
	First fir;
	/*
	class First {
		public: 
			First() {
				cout << "first class constructor() " << endl;
				Scnd sec;
					}
};
이럴때만 first가 먼저 출력이고 
Scnd sec가 저 상황일때 제외하고 어디에있던
(public 밖이던 public안에서 First()보다 앞이던 뒤던)
second가 먼저 출력됨
세컨드가 first의 멤버로 들어가 있어서 먼저 초기화 해줘야 하기 떄문


	*/
	return 0;
}



#include <iostream>

using namespace std;
class Something {
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[10];
public:
	//Something() {
	//	m_i = 1;
	//	m_d = 3.14;
	//	m_c = 'a';
	//	m_arr[0] = 1;
	//}
	Something()
		:m_i(2),/* m_d = 3.14  안됨*/ m_d(3.14), m_c('a'), m_arr{ 1,2,3,4,5,6,7,8,9,10 }{}
};
struct dele {
private: 
	int x=100 ;
	int y=1000;
public:
	dele()
		: x{ 1 }, y{ 2 }
	{
		cout << "does this work?" << endl;
		x = 7;
		cout << x << " " << y << endl;

	}

};

int main() {
	dele del;
	// 지금 dele의 생성자에 좆도 없는 상황인데 
	//dele del(); 이러면 프로토타입 함수가 호출되지 않았습니다 라고 뜸
	// private 구간에 변수를 초기화 해도 생성자에서 초기화한게 우선이 돼서
	// 7 2 가 찍힘 만약 생성자에서 초기화를 안했으면 private에서 초기화한게 찍히구
	// 생성자 initializer list ( : 쓰는거)로 일빠따 초기화 -> 그다음 생성자 내부에서 초기화 
	/*
	결론 : 
	constructor initializer list
	constructor 내부
	---- 만약 construtctor 에 초기화목록없다?
	그럼 private에 있는 초기화값 use
	*/

	return 0;
}


#include <iostream>
using namespace std;

class Simple {
private : 
	int m_id;
public:
	Simple(int id) {
		this->setID(id);//화살표 operator는 class , struct가 포인터일때 member selection operator
	//	(*this).setID(id);
		// (*this).setID(id) == this -> setID(id);
		//this->m_id;
		cout << this << endl; // self 주소
	/*	this->getID(); simple안의 함수면 
		cout << this << endl; this를 찍어도 같은주소로 찍힘
		this->Simple::getID();  이거나 그냥 getID()나 같음*/ 
	}
	void setID(int id) { m_id = id; }
	int getID() {
		return m_id;
	}
};
int main() {
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);
	/*Simpel s1(1),s2(2) 에서 바로 생성자로 들어가는데(디버깅할때)
	그러면 this 를 통해서 s1,s2의 주소가 찍힘
	*/
	cout << &s1 << " " << &s2;
	
	return 0;
}