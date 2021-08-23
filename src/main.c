#include <stdio.h>
#include "NeuralNetwork/Perceptron.h"

int main(){

    float input[] = {1,2,3};
    float weights[] = {1,1,1};

    Perceptron * perceptron = InitPerceptron();
    FeedForward(input,weights,3,0.1,perceptron);
    SummingFunction(perceptron);
    SetActivationFunction(perceptron,THRESHOLD);
    OutputFromActivationFunction(perceptron);
    FreePerceptron(perceptron);

    return 0;

}