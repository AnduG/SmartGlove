#include "interpreter.h"
#include "math.h"

  int classify(float values[INPUTS]) {
    float scores[CLASSES];
    for (int i = 0; i < CLASSES; i++) {
      scores[i] = make_score(values, i);
    }
    int guess;
    float prob;
    softmax(scores, &guess, &prob);
    if (prob > 80) {
      return guess;
    } else {
      return -1;
    }
  }

  float make_score(float values[INPUTS], int row) {
    float score = bias[row];
    for (int j = 0; j < INPUTS; j++) {
      score += weights[row][j] * values[j];
    }
    return score;
  }

  void softmax(float scores[CLASSES], int* guess, float* prob) {
    float max_score = -INFINITY;
    for (int i = 0; i < CLASSES; ++i) {
      if (scores[i] > max_score) { 
        max_score = scores[i];
        *guess = i;
      }
    }
    float sum = 0;
    for(int i = 0; i < CLASSES; i++) {
      scores[i] = expf(scores[i] - max_score);
      sum += scores[i];
    }
    *prob = 100.0f / sum;
  }

  char translate(int x) {
    return 'A' + x;
  }
