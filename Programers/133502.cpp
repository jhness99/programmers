//�ܹ��� �����
/*
* Ǯ��
* ó������ string���� �ӽù��ڿ��� ����� �ű⿡ �����ϰ�
* find�� �̿��� 1234�� ã���� �ش�κ��� �����ְ� ���������
* �ð��ʰ��� ���� ����
* 
* ���� ���͸� �̿��� stack�������� �׾��ִٰ�
* 1231�� ������ ������ 4�� pop�� ���ְ� �ܹ��� ������ ��������
* ���� ������ Ȯ�� �ϵ��� �ߴ��� ���
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    //�ӽ÷� ���ڸ� ������ ����
    vector<int> temp;

    for (int i = 0; i < ingredient.size(); i++) {

        //��������
        temp.push_back(ingredient[i]);

        //�ӽ� ���� ũ�Ⱑ 4 �̻��̰�, ���� �������� 1�ϰ��(1231�� �� �ϰ��)
        if (temp.size() >= 4 && temp.back() == 1) {
            if (temp[temp.size() - 2] == 3 &&
                temp[temp.size() - 3] == 2 &&
                temp[temp.size() - 4] == 1) {

                for (int j = 1; j <= 4; j++) {
                    temp.pop_back();
                }
                answer++;
            }

        }
    }
    return answer;
}