#include<bits/stdc++.h>
using namespace std;

int n;
int a[3], visited[64][64][64];
struct A {
	int a, b, c;	
};
queue<A> q;
int damege[6][3] = {
	{9, 3, 1},	
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

int solve(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({a, b, c});
	
	while(q.size()) {
		
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();
		
		if(visited[0][0][0]) {
			break;
		}
		
		for(int i=0; i<6; i++) {
			int na = max(0, a - damege[i][0]);
			int nb = max(0, b - damege[i][1]);
			int nc = max(0, c - damege[i][2]);
			
			if(visited[na][nb][nc])
				continue;
			
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({na, nb, nc});
		}
	}
	
	return visited[0][0][0] - 1;
}

int main() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	cout << solve(a[0], a[1], a[2]) << "\n";
}
