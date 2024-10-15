import csv                         # To load the dataset
import numpy as np                 # For easier manipulation of data
import matplotlib.pyplot as pyplot # To plot the data

# Read CSV data into two arrays
x = []
y = []
with open('linear_regression_data.csv', 'r') as csvfile:
    reader = csv.reader(csvfile)
    
    # Separate csv data into x and y
    for row in reader:
        x.append(float(row[0])) 
        y.append(float(row[1]))

# Convert csv data into numpy arrays
x = np.array(x)
y = np.array(y)
n = len(x)

# Calculate slope and intercept of regression line based on lecture notes
k = (n * np.sum(x * y) - (np.sum(x) * np.sum(y))) / (n*np.sum(x*x) - pow(np.sum(x), 2))
b = (np.sum(y) - k * np.sum(x)) / n

print(f'Slope: {k}')
print(f'Intercept: {b}')

# Generate the line based on the slope and intercept
xline = np.linspace(min(x), max(x), 100)
yline = k * xline + b

# Set up the plot with data from csv and regression line
pyplot.scatter(x, y)
pyplot.plot(xline, yline, color='red', label='Linear Model: y = kx + b')
pyplot.title("Linear Regression with Covariance")
pyplot.show()