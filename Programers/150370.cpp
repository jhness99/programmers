//�������� ���� ��ȿ�Ⱓ
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int days = stoi(today.substr(8, 2));

    //today�� �� �� ���� �� ���� ��ȯ�ؼ� ����
    int todayD = year * 12 * 28 + (month - 1) * 28 + days;

    map<char, int> mTerms;

    //������ char�� �������� ����� ��ȿ�Ⱓ ����
    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char c;
        int month;
        ss >> c >> month;
        mTerms[c] = month;
    }
    vector<int> ar;

    //�� ���������� �������� �� ���� ����
    for (auto& str : privacies) {
        int y = stoi(str.substr(0, 4));
        int m = stoi(str.substr(5, 2));
        int d = stoi(str.substr(8, 2));
        char c = str.back();

        int temp = y * 12 * 28 + (m - 1) * 28 + d + mTerms[c] * 28 - 1;
        ar.push_back(temp);
    }

    for (int i = 0; i < ar.size(); i++) {
        if (ar[i] < todayD) {
            answer.push_back(i + 1);
        }
    }


    return answer;
}