#include <iostream>
#include <sstream>
#include <ctime>
#include <locale>
#include <iomanip>

int main() {
    std::string inp("2010-42-10");
    std::string format("%Y-%m-%d");

    std::istringstream iss(inp);
    std::tm tm = {};

    iss >> std::get_time(&tm, format.c_str());

    if (iss.fail()) {
        std::cout << "Tarih ayrıştırma hatası!" << std::endl;
    } else {
        std::time_t t = std::mktime(&tm);
        std::cout << "Ayrıştırılan tarih: " << std::ctime(&t);
    }

    return 0;
}
