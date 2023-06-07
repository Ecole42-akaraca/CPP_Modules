#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::pair<std::string, int>>player;
    std::string name;
    int score;
    while (1)
    {
        std::getline(std::cin, name);
        if (name.empty())
            break;
        std::cin  >> score;

        player.push_back(make_pair(name, score));
		std::cout << score << std::endl;

        // clear the std::cin buffer else the next std::getline won't wait next input
        std::cin.seekg(0, std::ios::end);
        std::cin.clear();
    }

    return 0;
}