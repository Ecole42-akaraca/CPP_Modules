#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {
    std::string str = "Bu bir örnek cümledir";
    std::stack<std::string> myStack;

    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        myStack.push(word);
    }

    // Stack'teki elemanları yazdırma
    while (!myStack.empty()) {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }

    return 0;
}
