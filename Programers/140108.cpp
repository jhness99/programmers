//문자열 나누기
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCount = 0;
    int nonxCount = 0;
    char x;
    for (int i = 0; i < s.length(); i++) {
        //첫 시작이면 해당 문자를 x로 지정
        if (xCount == 0)
            x = s[i];

        if (s[i] == x) xCount++;
        else nonxCount++;

        //x의 출현횟수와 x가 아닌 문자의 출현횟수가 같을 경우 카운트 초기화 및 단어갯수추가
        //만약 출현횟수가 같지 않더라도 마지막이라면 단어로 추가
        if (xCount == nonxCount || i == s.length() - 1) {
            xCount = 0;
            nonxCount = 0;
            answer++;
        }
    }
    return answer;
}