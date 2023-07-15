#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Dice {
protected:
    std::vector<int> numbers;

public:
    Dice(const std::vector<int>& numbers) : numbers(numbers) {}

    int roll() {
        int index = rand() % numbers.size();
        return numbers[index];
    }
};

class SixSidedDice : public Dice {
public:
    SixSidedDice() : Dice({ 1, 2, 3, 4, 5, 6 }) {}
};

class FourSidedDice : public Dice {
public:
    FourSidedDice() : Dice({ 1, 2, 3, 4 }) {}
};

class TwelveSidedDice : public Dice {
public:
    TwelveSidedDice() : Dice({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }) {}
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    SixSidedDice sixSided;
    FourSidedDice fourSided;
    TwelveSidedDice twelveSided;

    int sum = 0;

    std::cout << "Rolling a six-sided die..." << std::endl;
    int value1 = sixSided.roll();
    std::cout << "Value: " << value1 << std::endl;
    sum += value1;

    std::cout << "Rolling a four-sided die..." << std::endl;
    int value2 = fourSided.roll();
    std::cout << "Value: " << value2 << std::endl;
    sum += value2;

    std::cout << "Rolling a twelve-sided die..." << std::endl;
    int value3 = twelveSided.roll();
    std::cout << "Value: " << value3 << std::endl;
    sum += value3;

    std::cout << "Sum of rolled values: " << sum << std::endl;

    return 0;
}
