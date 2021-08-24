#include "NeuralNetwork.h"

Neural InitNeuralNetwork(){

    Neural instance;

    instance.percetoron = InitPerceptron();
    instance.learningRate = 0.5;
    instance.trainingEpochs = 100;
    
    return instance;

}

void train(Neural instance,int ** trainingData,int rowSize,int colSize){

    


}


