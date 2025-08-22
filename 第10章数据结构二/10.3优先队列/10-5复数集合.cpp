#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
struct Complex{
    int re;
    int im;
    //构造一个函数在类的内部，名字和类名一样，没有返回值
    Complex(int _re, int _im){
        re = _re;
        im = _im;
    }
};
/* 自定义一个 < 的运算符：运算符重载
重载 < 原本的小于号，有两个参数，返回值是bool
自定义一个函数，参数数量不变，返回值类型不变，名字是operator
若a<b 返回ture 大根堆
若a>b 返回false 小根堆
*/
bool operator < (Complex lhs, Complex rhs){
    if (lhs.re*lhs.re+lhs.im*lhs.im < rhs.re*rhs.re+ rhs.im*rhs.im){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    priority_queue<Complex> pqueue;
    for (int i = 0; i < n; ++i){
        char actionArr[30];
        scanf("%s", actionArr);
        string action = actionArr;
        if (action == "Pop"){  // 注意：题目输入是 "Pop"，不是 "pop"
            if (pqueue.empty()){
                printf("empty\n");
            }
            else{
                printf("%d+i%d\n", pqueue.top().re, pqueue.top().im);
                pqueue.pop();
                printf("SIZE = %zu\n", pqueue.size());
            }
        }
        else if (action == "Insert"){
            int re, im;
            scanf("%d+i%d", &re, &im);  // 读取 1+i2
            Complex c(re, im);
            pqueue.push(c);
            printf("SIZE = %zu\n", pqueue.size());
        }
    }
    return 0;
}
