/*

    Example code : Use of Perceptron.h to train a and gate 

*/

#include <stdio.h>
#include "NeuralNetwork/Perceptron.h"
#include <time.h>
#include <stdlib.h>

#define ROW_SIZE 4
#define COLUMN_SIZE 2
#define SIZE 2
#define EPOCHS 100
#define LEARNING_RATE 0.4

int main(){

    srand(0);

    float bias = -0.5;

    // Forming the Traing set 
    float input [ROW_SIZE][COLUMN_SIZE] = {

        {0 , 0},
        {1 , 1},
        {0 , 1},
        {1 , 0}

    };

    // Setting the weights
    float weights [] = {rand()%4,rand()%4};

    //Initializing The perceptron
    Perceptron * perceptron = InitPerceptron();


    //Training the perceptron
    for(int i = 0;i < EPOCHS;i++){
        for(int j = 0;j < ROW_SIZE;j++){

            FeedForward(input[j],weights,SIZE,bias,perceptron);
            SummingFunction(perceptron);
            SetActivationFunction(perceptron,THRESHOLD);
            OutputFromActivationFunction(perceptron);
            float actualOutput = input[j][0] * input[j][1];
            float error = actualOutput - GetOuput(perceptron);

            weights[0] += error * LEARNING_RATE * input[j][0];
            weights[1] += error * LEARNING_RATE * input[j][1];
            bias += error * LEARNING_RATE;

            printf("[%f,%f]\t\t\t%f\t\t\t%f\n",input[j][0],input[j][1],GetOuput(perceptron),actualOutput); 
        }
    }

    //Freeing the perceptron
    FreePerceptron(perceptron);
        
    return 0;

}