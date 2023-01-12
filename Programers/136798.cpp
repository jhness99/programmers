//���ܿ��� ����
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    //1���� number������ ���� ����� Ȯ��
    for (int i = 1; i <= number; i++) {
        //����� ������ �� kg�̹Ƿ� weight, ��� ���� �ڱ��ڽ��� ����� ������ �ֱ� ������ �⺻���� 1
        int weight = 1;

        //�ڽŰ� 1�� ������ ��� ����� ���� ���� ������ ���� �� �����Ƿ�
        //(���� ���� ����� 1 ������ 2�̹Ƿ� ������ ������ ���� ū ����� 
        //���� Ŀ ���� ���� ���� ������ �� �ۿ� ����)
        //�ڱ��ڽ� + 1�� ������ ����� ���ϸ� �� ����� ������ ������ �ȴ�.
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0)
                weight++;
        }
        
        //����� �� ������ limit�� ������ �־��� ������power�� ����
        if (weight > limit)
            weight = power;
        answer += weight;
    }

    return answer;
}