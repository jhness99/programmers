//�˾���2
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    /*
    * ù��° �ڵ�, ���ڿ����� ���� �ߺ��Ǵ� ��� string �� !�� �ٲ���ȴ�. 
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
    * �ι�° �ڵ�, �ٸ������ Ǯ�̸� ���� �ۼ�
    * ù��° �ڵ�ó�� ��� �ߺ����ڿ��� ������ �ʰ� flag�� ī��Ʈ ���༭ �ߺ��̵Ǵ� ���ڸ� ��������
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