#include <functional>
#include <string>
#include <iostream>

class Coin
{
public:
    Coin() {}

    // Non-static member function.
    std::string Flip ()
    {
        srand(23);
        int side = rand() % 2 + 1;
        return (side == 1) ? "heads." : "tails.";
    }

    // Static member function.
    static std::string StaticFlip()
    {
        srand(23);
        int side = rand() % 2 + 1;
        return (side == 1) ? "heads." : "tails.";
    }
};

// Flipper is a generic function object wrapper that works with free functions,
// function objects, static member functions, and non-static member functions.
typedef std::function<std::string ()> Flipper;

std::string Flip(Flipper flipper)
{
    return flipper();
}

int main()
{
    // Example with non-static member function
    Coin coin;

    // Bind a Coin instance along with a Coin::Flip member function pointer.
    Flipper flipper1 = std::bind(&Coin::Flip, &coin);

    std::cout << "Flipping a coin..." << std::endl;
    std::string output = Flip(flipper1);
    std::cout << "The coin came up " << output << std::endl;

    // Example with static member function
    Flipper flipper2 = &Coin::StaticFlip;
    std::cout << "Flipping a coin..." << std::endl;
    output = Flip(flipper2);
    std::cout << "The coin came up " << output << std::endl;

    return 0;
}