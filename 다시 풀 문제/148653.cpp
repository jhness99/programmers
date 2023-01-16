#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int storey) {
    int answer = 0;

    while (storey) {
        int num = storey % 10;
        int nextNum = (storey / 10) % 10;

        if (num > 5) {
            answer += 10 - num;
            storey += 10;
        }
        else if (num == 5) {
            answer += 5;
            storey += nextNum >= 5 ? 10 : 0;
        }
        else {
            answer += num;
        }
        storey /= 10;
    }

    return answer;
}