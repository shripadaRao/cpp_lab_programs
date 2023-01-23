#include <iostream>
#include <stack>
#include <string>

std::string reverseString(std::string str) {
    std::stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    std::string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main() {
    std::string str = "hello";
    std::cout << "Original string: " << str << std::endl;
    std::string reversed = reverseString(str);
    std::cout << "Reversed string: " << reversed << std::endl;
    return 0;
}
