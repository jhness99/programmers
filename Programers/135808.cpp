//과일장수
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    //첫번째 풀이
    //맞는것같지만 틀렸다. 이유는 상자안에 다 안들어가면 버려야 하는데 버리지 않고 
    //갯수가 부족하지만 상자 크기만큼 탐색하고있다.
    /*
    sort(score.rbegin(), score.rend());
    for(int i = 0; i < score.size(); i+=m){
        int minNum = k+1;
        for(int j = 0; j < m; j++){
            minNum = min(minNum, score[i+j]);
        }
        answer += minNum*m;
    }
    */
    //위의 문제를 기반으로 다시 작성한 코드, 
    //박스가 채워지는 수를 계산해 정렬 한 후 박스수만큼만 체크해준다
    //이렇게 되면 남는 부분은 버려지므로 틀리지 않는다.
    sort(score.rbegin(), score.rend());
    int boxNum = score.size() / m;
    int index = m-1;
    //박스 개수만큼만 반복
    for(int i = 0; i < boxNum; i++ ){
        answer += score[index] * m;
        index += m;
    }
    //다른 사람이 우선순위 큐를 사용해서 참고로 우선순위큐를 이용해 본 코드
    /*
    priority_queue<int> pq;

    for(int i = 0; i < score.size();i++)
        pq.push(score[i]);

    while (pq.size() >= m){
        for(int i = 0; i < m-1; i++) pq.pop();
        answer += pq.top() * m;
        pq.pop();
    }
    */
    return answer;
}