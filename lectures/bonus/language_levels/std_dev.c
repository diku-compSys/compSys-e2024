#include <stdio.h>

void main()
{
    int n = 6;
    int data[] = { 11, 12, 13, 14, 15, 16 };

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
 
    float mean = total / n;
 
    float total_deviation = 0;
 
    for (int i = 0; i < n; i++) {
        total_deviation += (data[i] - mean) * (data[i] - mean);
    }
 
    float variance = total_deviation / n;
 
    float standardDeviation = variance / variance;
}
