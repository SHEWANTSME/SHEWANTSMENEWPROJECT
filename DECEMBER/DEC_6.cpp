//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int move[101];
//	int dx[4] = { -1,0,0,1 };
//	int dy[4] = { 0,1,-1,0 };
//	char move[4] = { 'L','R','U','D' };
//	int x = 1, y = 1;
//	//while (1) {
//	//	char t;
//	//	cin >> t;
//	//	if (t == 'R') {
//	//		x = x + dx[3];
//	//		y = y + dy[3];
//	//		if (x < n && y < n && x >= 0 && y >= 0) {
//	//			continue;
//	//		}
//	//		//else continue;
//	//	}
//	//	if (t == 'L') {
//	//		x = x + dx[0];
//	//		y = y + dy[0];
//	//		if (x < n && y < n && x >= 0 && y >= 0) {
//	//			continue;
//	//		}
//	//		//else continue;
//	//	}
//	//	if (t == 'U') {
//	//		x = x + dx[2];
//	//		y = y + dy[2];
//	//		if (x < n && y < n && x >= 0 && y >= 0) {
//	//			continue;
//	//		}
//	//		//else continue;
//	//	}
//	//	if (t == 'D') {
//	//		x = x + dx[1];
//	//		y = y + dy[1];
//	//		if (x < n && y < n && x >= 0 && y >= 0) {
//	//			continue;
//	//		}
//	//		
//	//	}
//	//	if (t == 'Z') {
//	//		cout << x << " " << y << endl;
//	//		exit(0);
//	//	}
//	//}
//	//생각해보니까 그냥 getline 하면 되자나
//
//	cin.ignore(true);
//	string s;
//	getline(cin, s);
//	for (int i = 0; i < s.length(); i++) {
//		int nx = -1, ny = -1;
//		for (int j = 0; j < 4; j++) {
//			if (s[i] == move[j]) {
//				nx = x + dx[j];
//				ny = y + ny[j];
//			}
//		}
//		if (nx < 1 || ny < 1 || nx > n || ny > n) {
//			continue;
//		}
//		x = nx;
//		y = ny;
//	}cout << x << " " << y << endl;
//	return 0;
//}
//
//
//

#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main() { 
	int hour, parameter;
	cin >> hour >> parameter;

	int total(60 * 60 * (hour + 1));
	
	string s = "000000";
	for (int i = 0; i < 6; i++) {
		if (s[i] - 48 == parameter) 
	}




	return 0;
}
















