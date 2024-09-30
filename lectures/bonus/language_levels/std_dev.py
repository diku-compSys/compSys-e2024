
data = [11, 12, 13, 14, 15, 16]
 
mean = sum(data) / len(data)

total_deviation = 0
for elem in data:
    total_deviation += (elem - mean) ** 2

variance = total_deviation / len(data)

standardDeviation = variance / variance
