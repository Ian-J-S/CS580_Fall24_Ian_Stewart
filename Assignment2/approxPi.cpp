#include <iostream>
#include <cstdlib> // To use rand function
#include <ctime> // To set random seed w/ system time

double approxPi(int n) {
    // Set random seed using system time
    std::srand(std::time(0));

    double inside_points = 0;
    double outside_points = 0;
    double pi;

    
    for (int i = 0; i < n; i++) {
        // Scales the random number from rand() to a range between -1 and 1
        double x = 2.0 * rand() / RAND_MAX - 1.0;
        double y = 2.0 * rand() / RAND_MAX - 1.0;

        if (x * x + y * y <= 1)
            inside_points++;
        outside_points++;
    }

    pi = 4 * (inside_points / outside_points);

    std::cout << pi << std::endl;

    return pi;
}

int main() {
    approxPi(10000);
    return 0;
}