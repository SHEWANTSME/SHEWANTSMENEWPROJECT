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
	//some.setvalue(30); sth�� const�� �Ѵٴ°� ���ΰ���
	//�ȹٲٷ��� �׷��°ǵ� �� �ٲٳİ� �״ϱ� ��������
	some.getvalue();
	// some.getvalue()�� �Ƿ��� const Sth some; ���� const�� ������
	// int getvalue(){ return value}���� getvalue�� ���� �ٲ��� �ʴ� �Լ��̴�
	//��� ��Ȯ�� ���� ���ִ� Ű���� const�� �־������(c++���밡���� �� ���ϸ�
	//setvalueó�� �����ϱ⶧���� �������
	return 0;
}