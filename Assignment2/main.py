import random

def approxPi(n):
    radius = 1
    points_inside = 0
    points_outside = 0

    # Generate a random point at each iteration and
    # check if it is inside the circle
    for i in range(0, n):
        # Generate coordinates for random point
        x = random.uniform(-radius, radius)
        y = random.uniform(-radius, radius)

        # Check if point is inside circle or not
        if (pow(x, 2) + pow(y, 2) <= 1):
            points_inside += 1
        points_outside += 1

    print(4 * (points_inside / points_outside))

    return 0

def main():
    approxPi(10000000)

if __name__ == "__main__":
    main()