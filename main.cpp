#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// 加法
double add(double a, double b) {
    return a + b;
}

// 减法
double subtract(double a, double b) {
    return a - b;
}

// 乘法
double multiply(double a, double b) {
    return a * b;
}

// 除法
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("除数不能为 0");
    }
    return a / b;
}

// 解析并计算表达式（当前分支只支持 + 和 -）
double evaluate(double a, char op, double b) {
    switch (op) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        default:
            throw std::invalid_argument(std::string("不支持的运算符: ") + op);
    }
}

int main() {
    std::cout << "请输入一个二元算式(如 3 + 5): ";
    double a, b;
    char op;
    if (!(std::cin >> a >> op >> b)) {
        std::cerr << "输入格式错误，应为: <数字> <运算符> <数字>" << std::endl;
        return 1;
    }

    try {
        double result = evaluate(a, op, b);
        std::cout << a << " " << op << " " << b << " = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}