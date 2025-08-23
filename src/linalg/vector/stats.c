#include "linalg/vector.h"
#include <math.h>

double gel_vector_mean(const Vector *v) {
    if (!v || v->size == 0) return NAN;

    double sum = 0.0;
    for (size_t i=0; i < v->size; i++) {
        sum += v->data[i];
    }
    return sum / v->size;
}

double gel_vector_variance(const Vector *v, int ddof) {
    if (!v || v->size == 0) return NAN;
    
    double mean = gel_vector_mean(v);
    double numerator = 0.0;
    for (size_t i = 0; i < v->size; i++) {
        numerator += (v->data[i] - mean) * (v->data[i] - mean);
    }

    return numerator / (v->size - ddof);
}
