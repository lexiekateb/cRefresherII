#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, int *argv[]) {

    // opening the file specified in the argument
    FILE *fptr = fopen(argv[1], "r");
    
    // first int of file is rows, second int is columns
    int rows, cols;
    fscanf(fptr, "%d", &rows);
    fscanf(fptr, "%d", &cols);

    // allocate appropriate memory for n number of fp values
    float* nums = (float*)malloc((rows * cols) * sizeof(float));

    // This reads in n number of floating point values
    int i, j;
    for(i=0; i< rows * cols; i++) {
        fscanf(fptr, "%f", &nums[i]);
    }

    // at this point, we have our array. now we need to transpose it into the output file

    // open the output file, write rows and cols inverted from input
    FILE *fout = fopen(argv[2], "w");
    fprintf(fout, "%d %d\n", cols, rows);
    
    // now we will access the array "inverted" and print out to the output file
    for(i=0; i < cols; i++) {
        for(j=0; j < rows; j++) {
            fprintf(fout, "%.2f ", nums[j * cols + i]);
        }

        fprintf(fout, "\n");  // every time we end a row, we need to put a newline

    }

    free(nums);
    
    return 0;
}