//옹알이2
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    /*
    * 첫번째 코드, 문자열에서 굳이 중복되는 모든 string 을 !로 바꿔버렸다. 
    * 
    */
    /*
    vector<string> badList = { "ayaaya", "yeye", "woowoo", "mama" };
    
    int index = 0;
    for (int i = 0; i < babbling.size(); i++) {
        bool check = false;
        for (auto& word : badList) {
            if ((index = babbling[i].find(word)) != string::npos) {
                babbling[i] = "!";
            }
        }
        cout << babbling[i] << " ";
        for (int j = 0; j < babbling[i].size(); j++) {
            if (babbling[i].substr(j, 3) == "aya") j += 2;
            else if (babbling[i].substr(j, 2) == "ye") j += 1;
            else if (babbling[i].substr(j, 3) == "woo") j += 2;
            else if (babbling[i].substr(j, 2) == "ma") j += 1;
            else {
                check = true;
                break;
            }
        }
        if (!check) answer++;
    }
    */
    /*
    * 두번째 코드, 다른사람의 풀이를 보고 작성
    * 첫번째 코드처럼 모든 중복문자열을 없에지 않고 flag로 카운트 해줘서 중복이되는 문자를 제거해줌
    */
    for (int i = 0; i < babbling.size(); i++) {
        bool check = false;
        int flag = 0;

        for (int j = 0; j < babbling[i].size(); j++) {
            if (babbling[i].substr(j, 3) == "aya" && flag != 1) { flag = 1; j += 2; }
            else if (babbling[i].substr(j, 2) == "ye" && flag != 2) { flag = 2; j += 1; }
            else if (babbling[i].substr(j, 3) == "woo" && flag != 3) { flag = 3; j += 2; }
            else if (babbling[i].substr(j, 2) == "ma" && flag != 4) { flag = 4; j += 1; }
            else {
                check = true;
                break;
            }
        }
        if (!check) answer++;
    }
    

    return answer;
}