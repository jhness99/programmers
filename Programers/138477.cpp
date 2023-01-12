//명예의 전당
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    //명예의 전당을 저장해줄 백터 선언
    vector<int> ranking;
    for (auto& scr : score) {

        //해당 점수를 명예의 전당에 추가
        ranking.push_back(scr);

        //내림차순으로 정렬
        sort(ranking.rbegin(), ranking.rend());

        //만약 명예의 전당의 사이즈가 k를 넘었다면, 마지막 원소를 제거하고 사이즈를 다시 원래 크기로 설정
        if (ranking.size() == k + 1) {
            ranking.pop_back();
            ranking.resize(k);
        }

        //발표 할 (가장 낮은)점수를 저장 
        answer.push_back(ranking.back());
    }

    return answer;
}