#include "Perceptron.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOTAL_NO_OF_ACTIVATIONFUNCIONS 7

typedef struct _Perceptron{

    float * input;
    float output;
    int size;
    ActivationFunctionIndex index;

}_perceptron;


static float ActivationFunctionReLU(float input){

    if(input < 0)
        return 0.0;
    else 
        return input;

}

static float ActivationFunctionTanh(float input){

    return (float)tanh(input);

}

static float ActivationFunctionLinear(float input){

    return input;

}

static float ActivationFunctionSoftmax(float input){



}

static float ActivateFunctionThreshold(float input){

    if(input < 0)
        return 0;
    else if(input >= 0)
            return 1;

}

static float ActivationFunctionPL(float input){

}

static float ActivationFunctionSigmoid(float input){

}

static float(*ActivationFUnction[])(float) = {

    ActivationFunctionReLU,
    ActivationFunctionTanh,
    ActivationFunctionLinear,
    ActivationFunctionSoftmax,
    ActivateFunctionThreshold,
    ActivationFunctionPL,
    ActivationFunctionSigmoid,

};

static void _FeedForward(float input[],float weights[],int size,_perceptron * p){

    if(p->input == NULL)
        p->input = (float *)calloc(size,sizeof(float));
    
    for(int i = 0;i < size;i++)
        p->input[i] = input[i] * weights[i];
    
    p->size = size;

}

static void Set_perceptronPointers(_perceptron * p){

    p->input = NULL;

}

static void _FreePerceptron(_perceptron * p){

    free(p->input);

}

static void _SummingFunction(_perceptron * p,float bias){

    int size = p->size;
    float output = bias;

    for(int i = 0;i < size;i++){
        output += p->input[i];
    }

    p->output = output;

}

static void _SetActivationFunction(_perceptron * p,ActivationFunctionIndex index){

    if(index < TOTAL_NO_OF_ACTIVATIONFUNCIONS)
        p->index = index;
    else 
        p->index = UNDEFINED;

}

static void _OutputFromActivationFunction(_perceptron * p){

    if(p->index == UNDEFINED){
        printf("ERROR : Undefined Actiation Function ! ");
        return;
    }

    p->output = (*ActivationFUnction[p->index])(p->output);
    
}

Perceptron * InitPerceptron(){

    Perceptron * instance = (Perceptron *)malloc(sizeof(Perceptron));

    instance->input = NULL;
    instance->weights = NULL;
    instance->m_perceptron = NULL;

    instance->m_perceptron = (_perceptron *)malloc(sizeof(_perceptron));

    Set_perceptronPointers(instance->m_perceptron);

    return instance;

}

void FeedForward(float input[],float weights[],int size,float bias,Perceptron * perceptron) {

    if(perceptron->input == NULL)
        perceptron->input = (float *)malloc(size*sizeof(float));
    
    if(perceptron->weights == NULL)
        perceptron->weights = (float *)malloc(size*sizeof(float));

    for(int i = 0;i < size;i++){

        perceptron->input[i] = input[i];
        perceptron->weights[i] = weights[i];

    }

    perceptron->bias = bias;

    perceptron->size = size;

    _FeedForward(perceptron->input,perceptron->weights,perceptron->size,perceptron->m_perceptron);

}

void SummingFunction(Perceptron * instance){

    _SummingFunction(instance->m_perceptron,instance->bias);

}

void SetActivationFunction(Perceptron * instace,ActivationFunctionIndex index){

    _SetActivationFunction(instace->m_perceptron,index);

}

void OutputFromActivationFunction(Perceptron * instacnce){

    _OutputFromActivationFunction(instacnce->m_perceptron);

}


void FreePerceptron(Perceptron * instance){

    free(instance->input);
    free(instance->weights);
    _FreePerceptron(instance->m_perceptron);
    free(instance->m_perceptron);
    free(instance);

}








