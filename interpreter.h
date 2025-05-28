#ifndef INTERPRETER_H
#define INTERPRETER_H

#define CLASSES 29
#define INPUTS 18

extern float weights[CLASSES][INPUTS];
extern float bias[CLASSES];

int classify(float values[INPUTS]);

void softmax(float scores[CLASSES], int* guess, float* prob);

float make_score(float values[INPUTS], int row);

char translate(int x);

#endif