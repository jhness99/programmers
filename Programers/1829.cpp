//īī�������� �÷�����
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//�����¿��� �̵���ǥ
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//�ִ밪�� 1 <= M N <= 100  �̹Ƿ� 101
//���⼭ ������ �߻��ߴµ�, ���α׷��ӽ� �����Ϸ� Ư���� ���������� �Լ� ������ �ʱ�ȭ �ؾ��Ѵٰ� �Ѵ�.
//�׷��� ���� dx dy�� ���⼭ �ʱ�ȭ �ߴµ� ������ ����...
//������ �� �𸣰ڴ�.
bool visited[101][101];
//bool visited[101][101] = {false,};
int N, M;

//BFS�� ���� ���� ���� Ž�� �� ������ ũ�� ��ȯ
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

            //Ž���ϴ� ���� ���� ���� �� �� ��� �湮ó�����ְ� queue�� �ְ� ������ ũ�⿡ 1�� �����ش�.
            if (picture[ny][nx] == picture[y][x]) {
                visited[ny][nx] = true;
                q.push({ nx, ny });
                size++;
            }
        }
    }
    return size;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    M = m;
    N = n;

    //���� visited �ʱ�ȭ
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            //���� �湮���� �ʾҰ� ���� ������� Ž������
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