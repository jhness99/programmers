//Ǫ������Ʈ ��ȸ
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    //���ڿ��� �߰���(������ ��ġ)�� �ε��� 
    int index = 0;

    for (int i = 1; i < food.size(); i++) {
        //�ش� ������ �� ��, Ȧ���ϰ�� --;
        int Size = food[i] % 2 == 0 ? food[i] : --food[i];
        
        //�ӽ÷� �� ���ڿ�
        string temp = "";

        for (int j = 0; j < Size; j++) {
            temp += to_string(i);
        }

        //���� ���ص״� �߰��� ���ڸ� ����
        answer.insert(index, temp);

        //�߰��� answer�� ���� / 2�� ����
        index = answer.length() / 2;
    }

    answer.insert(index, "0");
    return answer;
}