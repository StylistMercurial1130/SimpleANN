#ifndef __NEURALNETWORK_H__
#define __NEURALNETWORK_H__

#include "NeuralNetwork/Perceptron.h"
#include "stdlib.h"

typedef struct {

    Perceptron * percetoron;
    float error;
    float learningRate;
    float trainingEpochs;
    ActivationFunctionIndex index;

}Neural;

Neural InitNeuralNetwork();
void train(Neural instance,int ** trainingData,int rowSize,int colSize);

#endif