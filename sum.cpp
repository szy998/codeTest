#include <iostream>
#include <cmath>
int main() {
    int n, a, d, r;
    std::cout << "请输入项数 n: ";
    std::cin >> n;
    std::cout << "请输入第一项 a: ";
    std::cin >> a;
    std::cout << "请输入公差 d: ";
    std::cin >> d;
    std::cout << "请输入公比 r: ";
    std::cin >> r;

    for (int i = 0; i < n; i++) {
        int arithmeticSum = a + i * d;
        std::cout << arithmeticSum << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        int geometricSum = a * pow(r, i);
        std::cout << geometricSum << " ";
    }

    std::cout << std::endl;

    return 0;
}
