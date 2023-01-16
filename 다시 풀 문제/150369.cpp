//택배 배달과 수거하기
/*
* 여러모로 어려웠던 문제
* 코드의 구현 자체는 쉬운편이지만 문제를 푸는 법이 여려웠다
* 이번 문제는 그리디 문제였는데 수거와 배달을 나눠서 각각 체크하면서 배열의 값을 줄여가도록 했다가 실패했다.
* 그 후 찾아본 결과, 수거해야할 박스와 배달해야할 박스를 별개로 생각하지않고 하나의 시퀀스로 생각하는 것이다.
* 어차피 배달하고 나면 돌아올땐 공간이 0개로 되기때문에 배달과 수거를 동시에 처리할 수 있다.
* 각 수거와 배달의 한 사이클에 수거는 어디까지하고 배달은 어디까지 했는지를 체크하면 되는 문제였다.
* 그리고 두 값중 큰 값이 간 집의 위치므로 해당 위치의 2배를 하면 이동거리가 나온다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
//배달과 수거 백터를 가지고 1번 왔다갔다할때 이동하게 되는 거리를 저장한 백터를 반환하는 함수
//먼 곳부터 확인하게 되고 1번에 여러곳을 만족시키고 돌아올 수 도 있기때문에 순차적인 수는 아니다.
//그리디하게 거리를 저장하게 된다.
vector<int> DistanceFurthest(int cap, vector<int> v){
    vector<int> farthest;
    int index = v.size()-1;
    int capacity = cap;
    int furthestIndex = -1;
    while(index >= 0){
        if(v[index] == 0){
            index--;
            continue;
        }
        int diff = min(v[index], capacity);
        capacity -= diff;
        v[index] -= diff;

        furthestIndex = (furthestIndex == -1) ? index : furthestIndex;

        if(capacity == 0){
            farthest.push_back(furthestIndex + 1);
            capacity = cap;
            furthestIndex = -1;
        }
    }
    if (furthestIndex != -1)
    {
        farthest.push_back(furthestIndex + 1);
    }

    return farthest;
}
//위의 함수를 사용한 코드
//두 백터를 동시에 순차적으로 확인한다
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
     vector<int> deliveriesFarthest = DistanceFurthest(cap, deliveries);
    vector<int> pickupsFarthest = DistanceFurthest(cap,pickups);

    for (int i = 0, j = 0; i < deliveriesFarthest.size() || j < pickupsFarthest.size(); i++, j++)
    {
        //한 백터는 이미 끝까지 확인했는데 다른 백터가 아직 남아있을경우도 확인해서 처리해준다. 
        int deliveryMaxLen = i < deliveriesFarthest.size() ? deliveriesFarthest[i] : 0;
        int pickupMaxLen = j < pickupsFarthest.size() ? pickupsFarthest[j] : 0;

        //배달과 수거 백터중 더 큰 백터가 한번왔다갔다 했을때의 거리고
        //큰 백터가 아닌 다른 백터도 돌아올 때나 시작할 때 그 위치까지 가므로 둘다 index를 줄여주어서 체크한다.
        answer += max(deliveryMaxLen, pickupMaxLen) * 2;
    }

    return answer;
}
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    //가장 먼 곳부터 확인하기 위해 역순으로 바꾼다.
    reverse(deliveries.begin(), deliveries.end());
    reverse(pickups.begin(), pickups.end());

    //배달하거나 수거해야 하는 박스 수
    int d = 0;
    int p = 0;

    for (int i = 0; i < n; i++) {
        //배달하거나 수거해야하는 박스의 수 갱신
        d += deliveries[i];
        p += pickups[i];

        while (d > 0 || p > 0) {
            //한번 루프할때마다 1번씩 왔다갔다 하는것
            //이때 -가 될 수 있는데, 사실 -라는것은 현재 옮길 수 있는 최대 박스량이 남아있는 가장 먼 거리의 집에 옮겨야 하는 양보다 많아서
            //남는 만큼 다음에 작업해야 하는 곳에 뒀기 때문에 즉, 이미 작업했기 때문에 -가 있어도 다음 작업때 그만큼 덜 가지고 가는 것이므로 
            //상관이 없다!
            d-= cap;
            p -= cap;
            answer += (n - i) * 2;
        }
    }

    return answer;
}