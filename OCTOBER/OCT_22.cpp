#include <iostream>
#include <string>
using namespace std;
int main(){



//	char t;
	//cin >> t;
//cin.ignore();// 쓰는 이유,, 
	string str;
	getline(cin, str);
	int alphabet[26];
	int cnt[26];
	int tm = 0;



	for (int i = 0; i <100 ; i++) {
		if (str[i] == NULL) break;
		else {
			for (int j = 97; j < 122; j++) {
				if (str[i] == j) {
					
					alphabet[j - 97] = str[i]; 
					
				    cnt[j - 97] = i;
					
				}
			}


		}
		
		//cout << str[i] << endl;
	//	cout << tm-(48*t)<< endl;
		}
	for (int k = 97; k < 122; k++) {
		if (alphabet[k - 97]-97 <0) cout << -1 << endl;
		if (alphabet[k - 97] - 97 >= 0) {
			cout <<cnt[k - 97]  << endl;
		}
	}
//	cout << tm - (48 *t) << endl;

//	cout <<    << endl;
	//	cout << k << endl;
	/*
	while (t != 0) {
		k / (pow(10, t - 1)) = num[i];
	}*/
	
}