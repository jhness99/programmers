//햄버거 만들기
/*
* 풀이
* 처음에는 string으로 임시문자열을 만들어 거기에 저장하고
* find를 이용해 1234를 찾으면 해당부분을 지워주게 만들었지만
* 시간초과로 인해 오답
* 
* 따라서 백터를 이용해 stack형식으로 쌓아주다가
* 1231의 수열을 만나면 4번 pop을 해주고 햄버거 갯수를 증가시켜
* 좀더 빠르게 확인 하도록 했더니 통과
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    //임시로 숫자를 저장할 백터
    vector<int> temp;

    for (int i = 0; i < ingredient.size(); i++) {

        //숫자저장
        temp.push_back(ingredient[i]);

        //임시 백터 크기가 4 이상이고, 가장 마지막이 1일경우(1231의 끝 일경우)
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