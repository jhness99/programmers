//�ù� ��ް� �����ϱ�
/*
* ������� ������� ����
* �ڵ��� ���� ��ü�� ������������ ������ Ǫ�� ���� ��������
* �̹� ������ �׸��� �������µ� ���ſ� ����� ������ ���� üũ�ϸ鼭 �迭�� ���� �ٿ������� �ߴٰ� �����ߴ�.
* �� �� ã�ƺ� ���, �����ؾ��� �ڽ��� ����ؾ��� �ڽ��� ������ ���������ʰ� �ϳ��� �������� �����ϴ� ���̴�.
* ������ ����ϰ� ���� ���ƿö� ������ 0���� �Ǳ⶧���� ��ް� ���Ÿ� ���ÿ� ó���� �� �ִ�.
* �� ���ſ� ����� �� ����Ŭ�� ���Ŵ� �������ϰ� ����� ������ �ߴ����� üũ�ϸ� �Ǵ� ��������.
* �׸��� �� ���� ū ���� �� ���� ��ġ�Ƿ� �ش� ��ġ�� 2�踦 �ϸ� �̵��Ÿ��� ���´�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
//��ް� ���� ���͸� ������ 1�� �Դٰ����Ҷ� �̵��ϰ� �Ǵ� �Ÿ��� ������ ���͸� ��ȯ�ϴ� �Լ�
//�� ������ Ȯ���ϰ� �ǰ� 1���� �������� ������Ű�� ���ƿ� �� �� �ֱ⶧���� �������� ���� �ƴϴ�.
//�׸����ϰ� �Ÿ��� �����ϰ� �ȴ�.
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
//���� �Լ��� ����� �ڵ�
//�� ���͸� ���ÿ� ���������� Ȯ���Ѵ�
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
     vector<int> deliveriesFarthest = DistanceFurthest(cap, deliveries);
    vector<int> pickupsFarthest = DistanceFurthest(cap,pickups);

    for (int i = 0, j = 0; i < deliveriesFarthest.size() || j < pickupsFarthest.size(); i++, j++)
    {
        //�� ���ʹ� �̹� ������ Ȯ���ߴµ� �ٸ� ���Ͱ� ���� ����������쵵 Ȯ���ؼ� ó�����ش�. 
        int deliveryMaxLen = i < deliveriesFarthest.size() ? deliveriesFarthest[i] : 0;
        int pickupMaxLen = j < pickupsFarthest.size() ? pickupsFarthest[j] : 0;

        //��ް� ���� ������ �� ū ���Ͱ� �ѹ��Դٰ��� �������� �Ÿ���
        //ū ���Ͱ� �ƴ� �ٸ� ���͵� ���ƿ� ���� ������ �� �� ��ġ���� ���Ƿ� �Ѵ� index�� �ٿ��־ üũ�Ѵ�.
        answer += max(deliveryMaxLen, pickupMaxLen) * 2;
    }

    return answer;
}
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    //���� �� ������ Ȯ���ϱ� ���� �������� �ٲ۴�.
    reverse(deliveries.begin(), deliveries.end());
    reverse(pickups.begin(), pickups.end());

    //����ϰų� �����ؾ� �ϴ� �ڽ� ��
    int d = 0;
    int p = 0;

    for (int i = 0; i < n; i++) {
        //����ϰų� �����ؾ��ϴ� �ڽ��� �� ����
        d += deliveries[i];
        p += pickups[i];

        while (d > 0 || p > 0) {
            //�ѹ� �����Ҷ����� 1���� �Դٰ��� �ϴ°�
            //�̶� -�� �� �� �ִµ�, ��� -��°��� ���� �ű� �� �ִ� �ִ� �ڽ����� �����ִ� ���� �� �Ÿ��� ���� �Űܾ� �ϴ� �纸�� ���Ƽ�
            //���� ��ŭ ������ �۾��ؾ� �ϴ� ���� �ױ� ������ ��, �̹� �۾��߱� ������ -�� �־ ���� �۾��� �׸�ŭ �� ������ ���� ���̹Ƿ� 
            //����� ����!
            d-= cap;
            p -= cap;
            answer += (n - i) * 2;
        }
    }

    return answer;
}