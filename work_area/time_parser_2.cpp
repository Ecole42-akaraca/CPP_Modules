#include <iostream>
#include <sstream>

int main() {
    std::string inp("2023-06-14");
    std::string format("%Y-%m-%d");

    std::istringstream iss(inp);

    int year, month, day;
    char dash1, dash2;

    iss >> year >> dash1 >> month >> dash2 >> day;

    if (iss.fail() || dash1 != '-' || dash2 != '-') {
        std::cout << "Geçersiz tarih formatı!" << std::endl;
    } else {
        std::cout << "Ayrıştırılan tarih: " << year << "-" << month << "-" << day << std::endl;
    }

    return 0;
}
