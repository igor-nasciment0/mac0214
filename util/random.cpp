// auxiliary program for testing others

#include <iostream>
#include <random>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> dist(0, 1000000000);

    for (int i = 0; i < 1000; ++i) {
        std::cout << dist(gen) << "\n";
    }

    return 0;
}