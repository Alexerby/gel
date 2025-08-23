#include <stdio.h>
#include "linalg/vector.h"

int main(void) {

    // Create a vector of size 5
    Vector *v = gel_vector_create(5);
    if (!v) {
        fprintf(stderr, "Failed to create vector\n");
        return 1;
    }

    // Set values: {1.0, 2.0, 3.0, 4.0, 5.0}
    for (size_t i = 0; i < 5; i++) {
        if (gel_vector_set(v, i, (double)(i + 1)) != 0) {
            fprintf(stderr, "Failed to set value at index %zu\n", i);
            gel_vector_free(v);
            return 1;
        }
    }

    // Print vector
    printf("Vector contents: ");
    gel_vector_stdout(v);

    // Compute statistics
    double mean = gel_vector_mean(v);
    double variance = gel_vector_variance(v, 0);

    printf("Vector mean: %.2f\n", mean);
    printf("Vector variance: %.2f\n", variance);

    // Test empty vector
    Vector *empty = gel_vector_create(0);
    if (!empty) {
        fprintf(stderr, "Failed to create empty vector\n");
        gel_vector_free(v);
        return 1;
    }

    printf("Empty vector mean: %f\n", gel_vector_mean(empty));
    printf("Empty vector variance: %f\n", gel_vector_variance(empty, 0));

    // Free memory
    gel_vector_free(v);
    gel_vector_free(empty);

    return 0;
}
