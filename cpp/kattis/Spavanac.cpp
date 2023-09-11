#include <iostream>
#include <sstream>

int main() {
    int hours, minutes;
    std::cin >> hours >> minutes;

    if (minutes >= 45) {
        std::cout << hours << " " << (minutes - 45);
    }
    
    else {
        if (hours == 0) {
            std::cout << 23 << " " << (60 - (45 - minutes));
        } else {
            std::cout << (hours - 1) << " " << (60 - (45 - minutes));
        }
    }
    return 0;
}