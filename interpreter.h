#ifndef INTERPRETER_H
#define INTERPRETER_H

#define CLASSES 30
#define INPUTS 18

float weights[CLASSES][INPUTS];
float bias[CLASSES];

int classify(float values[INPUTS]);

void softmax(float scores[CLASSES], int* guess, float* prob);

float make_score(float values[INPUTS], int row);

char translate(int x);

#endif