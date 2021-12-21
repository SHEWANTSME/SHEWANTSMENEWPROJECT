#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include<queue>
#include<deque>
using namespace std;
//------------------------------------ 지저분하니까 끊어놔야징
bool visited[1001];
//int graph[1001];
vector<int>graph[1001];
vector<int>graph2[1001];
bool visiting[1001];
queue<int>q;
//------------------------------------ BFS
void BFS(int x) {// BFS 필요한것 -> bool visited, 이중 array, queue
	q.push(x); // 일단 queue에 push
	visiting[x] = true; // visit하긴 했으니 true
	while (!q.empty()) { // q에 값이 남아있으면 실행되는 while
		int m = q.front();// 앞에있는거 다른변수로 저장
		q.pop(); // 뺴버리고
		cout << m << " "; // 출력한다음
		for (int i = 0; i < graph2[m].size(); i++) { // 앞에있는놈과 연결된만큼의 사이즈를 for문돌리고
			int n = graph[m][i];
			if (!visiting[n]) { // 방문안했으면
				q.push(n); // queue에 집어넣고
				visiting[n] = true;//방문도 한거고
			}// 나중에 다 방문을 했으면 이놈if문을 안들어갈테니, 
			// 다 pop되어서 while 나오겠징
		}
	}
}
// ---------------------------------- DFS
void DFS(int x) { // DFS 필요한것 -> bool visited, 이중 array
	visited[x] = true;// 현재 노드 방문 했다고 체크
	cout << x << " "; // 출력
	for (int i = 0; i < graph[x].size(); i++) { // 노드 번호가 작은것부터 순서대로 DFS니까
		int y = graph[x][i];// main에서 정렬이 된 상태여야함
		if (!visited[y]) DFS(y);// 재귀적으로 방문 안했으면 들리기
	}
}
// ----------------------------------- MAIN
int main() {
	int node, line, start_num;
	cin >> node >> line >> start_num;
	while (line--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y); // 이렇게 양방향으로 해놔야 문제가 풀리더라고
		graph[y].push_back(x);
		graph2[x].push_back(y);
		graph2[y].push_back(x);
	}
	for (int i = 1; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end()); // sort를 오름차순으로 해줘야 노드번호가 작은것부터
		sort(graph2[i].begin(), graph2[i].end());// 순차적 방문이 가능함
	}
	DFS(start_num);
	cout << endl;
	BFS(start_num);
	return 0;
}