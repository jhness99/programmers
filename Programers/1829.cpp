//카카오프렌즈 컬러링북
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//상하좌우의 이동좌표
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//최대값이 1 <= M N <= 100  이므로 101
//여기서 오류가 발생했는데, 프로그래머스 컴파일러 특성상 전역변수를 함수 내에서 초기화 해야한다고 한다.
//그런데 위의 dx dy는 저기서 초기화 했는데 문제가 없다...
//이유를 잘 모르겠다.
bool visited[101][101];
//bool visited[101][101] = {false,};
int N, M;

//BFS로 색이 같은 공간 탐색 및 공간의 크기 반환
int BFS(int x, int y, const vector<vector<int>>& picture) {
    queue<pair<int, int>> q;
    int size = 1;
    q.push({ x,y });
    visited[y][x] = true;
    while (!q.empty()) {
        auto index = q.front();
        int x = index.first;
        int y = index.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
            if (visited[ny][nx]) continue;

            //탐색하는 곳의 색이 같은 색 일 경우 방문처리해주고 queue에 넣고 공간의 크기에 1을 더해준다.
            if (picture[ny][nx] == picture[y][x]) {
                visited[ny][nx] = true;
                q.push({ nx, ny });
                size++;
            }
        }
    }
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    M = m;
    N = n;

    //위의 visited 초기화
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            //만약 방문하지 않았고 색이 있을경우 탐색시작
            if (!visited[i][j] && picture[i][j]) {
                int Size = 0;
                if ((Size = BFS(j, i, picture))) {
                    number_of_area++;
                    max_size_of_one_area = max(Size, max_size_of_one_area);
                }
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}