//
// Created by hash on 2020/6/28.
//
#include "iostream"

using namespace std;
#define produce(x) x*x

#define productA(x) x

int main() {
    int i, j, l,m;
    i = 3;
    // ++ 优先于 * 执行的
    j = produce(i++); // x*x = 3 *4 =12
        // 3*4   i=5

    l = produce(++i); // （++5=6） * （++6=7） =42

    m = productA(2);

    cout << " test  j = " << j << " l =" << l << endl;
    return 0;
}
