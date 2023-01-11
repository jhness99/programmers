//가장 가까운 같은 글자
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    //입력된 문자열의 위치를 하나하나 저장해 줄 맵 생성
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        //맵에 해당 알파벳이 있는지 탐색
        auto index = m.find(s[i]);

        //알파벳이 없을경우
        if (index == m.end()) {
            m.insert({ s[i], i });
            answer.push_back(-1);
        }
        //알파벳이 있을경우
        else {
            answer.push_back(i - (index->second));
            index->second = i;  //해당 알파벳을 다시 출연한 위치로 갱신
        }
    }

    return answer;
}