#include "time_test.h"
#include "lenet.cpp"

int main()
{
    printf("Starting test...");
    float input[32][32] = {0};
    float output[10] = {0};
    clock_t t = clock();

    ActivateNetwork(input, output);
    t = clock() - t;
    double time_taken = 1000 * ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("ActivateNetwork() took %f milliseconds to execute.\n", time_taken);
}