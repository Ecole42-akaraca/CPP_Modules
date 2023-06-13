#include <iostream>
#include <vector>
#include <algorithm>

int shortestSpan(const std::vector<int>& numbers) {
    if (numbers.size() < 2)
        throw std::invalid_argument("Number of elements is too low!");

    std::vector<int> sortedNumbers = numbers; // Sayıları sıralamak için yeni bir vektör oluştur
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0]; // İlk iki sayı arasındaki farkı başlangıçta minimum kabul et

    for (size_t i = 2; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1]; // Şu anki sayı ile bir önceki sayı arasındaki farkı hesapla
        if (span < minSpan) {
            minSpan = span; // Minimum farkı güncelle
        }
    }

    return minSpan;
}

int main() {
    std::vector<int> numbers = {1557860134, 834647914, 564308394, 1043392806, 2098912687, 1859144787, 759371259, 257435892, 1692971786, 1765968199, 256035406, 1777323701, 2129396584, 953410033, 1586934364, 2006443655, 362800744, 886030575, 864265727, 134685381, 209434529, 240431470, 1514976283, 1640269549, 762733504, 932112785, 126372630, 83465527, 498290798, 1734702333};
    int minSpan = shortestSpan(numbers);
    std::cout << "Minimum span between two numbers: " << minSpan << std::endl;

    return 0;
}

