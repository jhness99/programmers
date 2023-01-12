//개인정보 수집 유효기간
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

    //today의 년 월 일을 일 수로 변환해서 저장
    int todayD = year * 12 * 28 + (month - 1) * 28 + days;

    map<char, int> mTerms;

    //맵으로 char를 기준으로 약관의 유효기간 저장
    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char c;
        int month;
        ss >> c >> month;
        mTerms[c] = month;
    }
    vector<int> ar;

    //각 개인정보의 보관가능 일 수를 저장
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