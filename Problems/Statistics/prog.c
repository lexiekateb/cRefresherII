#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// function to compute max
float findMax(float* nums, int n) {
    int i;
    float max = nums[0];

    for(i=0; i<n; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }

    return max;

}

// function to compute min
float findMin(float* nums, int n) {
    int i;
    float min = nums[0];

    for(i=0; i<n; i++) {
        if(nums[i] < min) {
            min = nums[i];
        }
    }

    return min;

}

// function to find the average

float findAvg(float* nums, int n) {
    int i;
    float avg = 0.0;
    for(i=0; i<n; i++) {
        avg += nums[i];
    }
    return(avg / n);
}

// function to compute standard deviation
float findSD(float* nums, int n) {
    int i;
    float SD = 0.0;
    
    // first, get the average
    float avg = findAvg(nums, n);

    for(i=0; i<n; i++) {
        SD += pow(nums[i] - avg, 2);
    }

    return sqrt(SD / n);

}

int main(int argc, int *argv[]) {

    // opening the file specified in the argument
    FILE *fptr = fopen(argv[1], "r");
    
    // first line of file is always an int of how many fp# to follow
    int n;
    fscanf(fptr, "%d", &n);

    // allocate appropriate memory for n number of fp values
    float* nums = (float*)malloc(n * sizeof(float));

    //This reads in n number of floating point values
    int k;
    for(k=0; k<n; k++) {
        fscanf(fptr, "%f", &nums[k]);
    }

    float max = findMax(nums, n);
    float min = findMin(nums, n);
    float avg = findAvg(nums, n);
    float SD = findSD(nums, n);

    // now we must write to our outfile
    FILE *fout = fopen(argv[2], "w");

    fprintf(fout, "Max: %.2f\n", max);
    fprintf(fout, "Min: %.2f\n", min);
    fprintf(fout, "Avg: %.2f\n", avg);
    fprintf(fout, "SD: %.2f\n", SD);

    free(nums);

    return 0;
}