#include <cstdlib> // To use rand function
#include <ctime> // To set random seed w/ system time
#include <fstream> // To write data to CSV file

// Approximate Pi via Monte Carlo Method
// n is the number of random points tested
// Randomized points are tested to see whether or not
// they fall within the unit circle, or are outside of the circle,
// but still inside a square of side length 2 centered at the origin.
double approxPi(int nPoints) {
    double inside_points = 0;

    for (int i = 0; i < nPoints; i++) {
        // Scales the random number from rand() to a range between -1 and 1
        double x = 2.0 * rand() / RAND_MAX - 1.0;
        double y = 2.0 * rand() / RAND_MAX - 1.0;

        if (x * x + y * y <= 1)
            inside_points++;
    }

    return 4 * (inside_points / nPoints);
}

void logData() {
    // Create and/or open csv file and append each write
    std::ofstream csv("pi_approximations.csv", std::ios::app);
    csv << "Sample size,Pi Approx" << std::endl;
    
    // Outer loop from 10 to 10k sample size in increments of 100
    for (int i = 10; i < 10000; i+=100) {
        // Inner loop tests pi at this sample size 10 (could be more) times
        for (int j = 0; j < 10; j++) {
            // Sample size, Pi_approx value
            csv << i << "," << approxPi(i) << std::endl;
        }
    }

    csv.close();
}

int main() {
    // Set random seed using system time
    std::srand(std::time(NULL));

    // Write pi approximations to csv
    logData();

    return 0;
}