//기사단원의 무기
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    //1부터 number까지의 수의 약수를 확인
    for (int i = 1; i <= number; i++) {
        //약수가 무기의 총 kg이므로 weight, 모든 수는 자기자신을 약수로 가지고 있기 때문에 기본무게 1
        int weight = 1;

        //자신과 1을 제외한 모든 약수는 원래 수의 절반을 넘을 수 없으므로
        //(가장 작은 약수인 1 다음이 2이므로 본인을 제외한 가장 큰 약수는 
        //가장 커 봐야 원래 수의 절반일 수 밖에 없다)
        //자기자신 + 1을 포함한 약수를 더하면 총 약수의 갯수가 나오게 된다.
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0)
                weight++;
        }
        
        //약수의 총 개수가 limit를 넘으면 주어진 고정값power로 설정
        if (weight > limit)
            weight = power;
        answer += weight;
    }

    return answer;
}