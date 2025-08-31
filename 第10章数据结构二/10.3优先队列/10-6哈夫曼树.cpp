#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pqueue;
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n; ++i){
        int leaf;
        scanf("%d",&leaf);
        pqueue.push(-1*leaf);
    }
    int wpl = 0;
    while(pqueue.size()>= 2){
        int leaf1 = pqueue.top();
        pqueue.pop();
        int leaf2 = pqueue.top();
        pqueue.pop();
        wpl += leaf1 +leaf2;
        pqueue.push(leaf1 + leaf2);
    }
    printf("%d\n", -1*wpl);
    return 0;
}
