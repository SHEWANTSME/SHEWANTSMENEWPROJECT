#include <iostream>
class Sth {
private :
	int value=0;
public : 
	//int value = 0;
	void setvalue(int invalue) {
		value = invalue;
	}
  int getvalue() const { return value; }
};

int main() {
	const Sth some;
	//some.setvalue(30); sth를 const로 한다는게 내부값을
	//안바꾸려고 그러는건데 왜 바꾸냐고 그니까 오류뜨지
	some.getvalue();
	// some.getvalue()가 되려면 const Sth some; 에서 const를 뺴던가
	// int getvalue(){ return value}에서 getvalue는 값을 바꾸지 않는 함수이다
	//라고 명확히 말할 수있는 키워드 const를 넣어줘야함(c++빡대가리라 말 안하면
	//setvalue처럼 생각하기때문에 써줘야함
	return 0;
}