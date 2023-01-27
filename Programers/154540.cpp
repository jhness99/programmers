#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[100][100] = { false, };

int R = 0, C = 0;

int BFS(int x, int y, const vector<string>& maps) {

    queue<pair<int, int>> q;
    q.push({ x , y });
    visited[y][x] = true;
    int sum = maps[y][x] - '0';
    while (!q.empty()) {
        auto index = q.front();
        q.pop();
        int x = index.first;
        int y = index.second ;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (!visited[ny][nx] && maps[ny][nx] != 'X') {
                    visited[ny][nx] = true;
                    sum += maps[ny][nx] - '0';
                    q.push({ nx, ny });
                }
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    C = maps.size();
    R = maps[0].length();

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(BFS(j, i, maps));
            }
        }
    }

    sort(answer.begin(), answer.end());
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}
