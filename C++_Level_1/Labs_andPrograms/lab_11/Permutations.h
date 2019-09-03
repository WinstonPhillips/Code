#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

void seedRandom();
int* initPermutation(int n);
void removePermutation (int* permutation, int permuteSize, int removeIndex);
int nextPermutation (int* permutation, int& permuteSize);

#endif