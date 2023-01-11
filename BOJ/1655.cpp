#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> maxQue;
	priority_queue<int, vector<int>, greater<int>> minQue;

	while (N--) {
		int input;
		cin >> input;
		if (maxQue.size() == minQue.size()) {
			maxQue.push(input);
		}
		else {
			minQue.push(input);
		}
		if (!maxQue.empty() && !minQue.empty() && maxQue.top() > minQue.top()) {
			int max_val, min_val;
			max_val = maxQue.top();
			min_val = minQue.top();
			maxQue.pop();
			minQue.pop();
			maxQue.push(min_val);
			minQue.push(max_val);
		} 
		cout << maxQue.top() << endl;
	}

	return 0;
}