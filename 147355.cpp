//크기가 작은 부분 문자열
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        //비교대상의 길이만큼 잘라서 저장
        string temp = t.substr(i, p.length());
        
        //자른 문자열을 숫자로 비교
        //처음에 stoi를 사용했지만 core dump 때문에 더 큰 long long int 형은 stoll사용
        if (stoll(temp) <= stoll(p))
            answer++;
    }
    return answer;
}