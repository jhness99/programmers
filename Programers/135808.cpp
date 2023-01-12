//�������
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    //ù��° Ǯ��
    //�´°Ͱ����� Ʋ�ȴ�. ������ ���ھȿ� �� �ȵ��� ������ �ϴµ� ������ �ʰ� 
    //������ ���������� ���� ũ�⸸ŭ Ž���ϰ��ִ�.
    /*
    sort(score.rbegin(), score.rend());
    for(int i = 0; i < score.size(); i+=m){
        int minNum = k+1;
        for(int j = 0; j < m; j++){
            minNum = min(minNum, score[i+j]);
        }
        answer += minNum*m;
    }
    */
    //���� ������ ������� �ٽ� �ۼ��� �ڵ�, 
    //�ڽ��� ä������ ���� ����� ���� �� �� �ڽ�����ŭ�� üũ���ش�
    //�̷��� �Ǹ� ���� �κ��� �������Ƿ� Ʋ���� �ʴ´�.
    sort(score.rbegin(), score.rend());
    int boxNum = score.size() / m;
    int index = m-1;
    //�ڽ� ������ŭ�� �ݺ�
    for(int i = 0; i < boxNum; i++ ){
        answer += score[index] * m;
        index += m;
    }
    //�ٸ� ����� �켱���� ť�� ����ؼ� ����� �켱����ť�� �̿��� �� �ڵ�
    /*
    priority_queue<int> pq;

    for(int i = 0; i < score.size();i++)
        pq.push(score[i]);

    while (pq.size() >= m){
        for(int i = 0; i < m-1; i++) pq.pop();
        answer += pq.top() * m;
        pq.pop();
    }
    */
    return answer;
}