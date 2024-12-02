#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdint>

class Apple {
public:
    Apple (uint8_t days_left) {
        days_left_ = days_left;
    }

    int get_days_left() { return days_left_; }

    /* - we can only use bitwise operations
       - integers have 8 bits */
    bool good_after (uint8_t day) {
        /* let's make a mask for each bit starting with the most significant */
        for (int bit=7; bit>=0; bit--) {
            uint8_t mask = 1 << bit; // bitwise left shift
            uint8_t masked_days_left = days_left_ & mask; // bitwise AND
            uint8_t masked_day = day & mask; // bitwise AND

            /* if they are different, we know which one is bigger */
            if (masked_days_left ^ masked_day) { // bitwise XOR
                /* if the bit in question is a 1 on the days left, 
                   then the apple is good after the requested day */
                return masked_days_left >> bit; // bitwise right shift
            }

            /* keep going until one of the bits is different or we don't have more bits */
        }

        /* if all bits are the same, the apple is only good until the day requested, not after */
        return false;
    }

private:
    uint8_t days_left_;
};

int main() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    std::vector<Apple> good_apples;
    std::vector<Apple> bad_apples;

    /* make a bunch of apples with random days left and check if they're good after 7 days */
    for (int i=0; i<10; i++) {
        /* let's say they are good for max 14 days and min 1 day*/
        uint8_t random_value = 1 + std::rand() / ((RAND_MAX + 1u) / 14); 
        Apple apple = Apple(random_value);

        if (apple.good_after(7)) {
            good_apples.push_back(apple);
        }
        else {
            bad_apples.push_back(apple);
        }
    }

    std::cout << "Good apples are good for: " << std::endl;
    for (int i=0; i<good_apples.size(); i++) {
        Apple apple = good_apples[i];
        std::cout << apple.get_days_left() << std::endl;
    }
    std::cout << "Bad apples are good for: " << std::endl;
    for (int i=0; i<bad_apples.size(); i++) {
        Apple apple = bad_apples[i];
        std::cout << apple.get_days_left() << std::endl;
    }

  return 0;
}