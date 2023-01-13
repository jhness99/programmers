//푸드파이트 대회
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    //문자열의 중간을(삽입할 위치)의 인덱스 
    int index = 0;

    for (int i = 1; i < food.size(); i++) {
        //해당 음식이 들어갈 양, 홀수일경우 --;
        int Size = food[i] % 2 == 0 ? food[i] : --food[i];
        
        //임시로 들어갈 문자열
        string temp = "";

        for (int j = 0; j < Size; j++) {
            temp += to_string(i);
        }

        //먼저 정해뒀던 중간에 문자를 삽입
        answer.insert(index, temp);

        //중간을 answer의 길이 / 2로 갱신
        index = answer.length() / 2;
    }

    answer.insert(index, "0");
    return answer;
}