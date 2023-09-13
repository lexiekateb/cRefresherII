#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, int *argv[]) {

    // opening the file specified in the argument
    FILE *fptr = fopen(argv[1], "r");

    // toupper(c)
    // we will read in each char and assign it to the index of its lowercase ASCII number.
        // i.e., a or A would both have an ASCII of 65, so for our array it will be index 0.
        // we are not considering punctuation or numbers in the histogram.

    int length = 122 - 97 + 1; // 26, the length of the alphabet. 122 is "z" and 97 is "a"
    int count[length];
    for(int i=0; i<length; i++) {
        count[i] = 0;   // init all array values as zero
    }
    
    int c;
    do {
        c = fgetc(fptr);
        count[c - 97]++;

        if(feof(fptr))
            break ;

    } while(1);


    // now print the histogram to output file
    FILE *fout = fopen(argv[2], "w");

    for(int i = 0; i < length; i++)
    {
        fprintf(fout, "%c | ", i + 97);
        for(int j = 1; j <= count[i]; ++j){
           fprintf(fout, "*");
         }
         fprintf(fout, "\n");
     }

}