//���� ����
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    //���� ������ �������� ���� ����
    vector<int> ranking;
    for (auto& scr : score) {

        //�ش� ������ ���� ���翡 �߰�
        ranking.push_back(scr);

        //������������ ����
        sort(ranking.rbegin(), ranking.rend());

        //���� ���� ������ ����� k�� �Ѿ��ٸ�, ������ ���Ҹ� �����ϰ� ����� �ٽ� ���� ũ��� ����
        if (ranking.size() == k + 1) {
            ranking.pop_back();
            ranking.resize(k);
        }

        //��ǥ �� (���� ����)������ ���� 
        answer.push_back(ranking.back());
    }

    return answer;
}