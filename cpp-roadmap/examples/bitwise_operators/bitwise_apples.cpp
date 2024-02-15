#include <iostream>
#include <bitset>

class Apple {
public:
    Apple(int id, int last_day){
        id_ = id; 
        last_day_ = last_day;
    }

    int get_id(){ return id_; }
    int get_last_day_(){ return last_day_; }

    bool good_after(int day){
        // we can only use bitwise operations
        // integers have 8 bits
        return false;
    }

private:
    int id_;
    int last_day_;
};

int main() {
    Apple myApple = Apple(0, 2);
    int a = 2;
    std::bitset<8> x(a);
    std::cout << x << '\n';

  return 0;
}