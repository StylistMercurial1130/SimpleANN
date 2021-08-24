#include "Perceptron.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOTAL_NO_OF_ACTIVATIONFUNCIONS 7
#define SLOPE_PARAMETER 0.5

/* 
    Private class _perceptron
*/

typedef struct _Perceptron{

    float * input;
    float output;
    int size;
    ActivationFunctionIndex index;

}_perceptron;



/*
    Actiavtion functions 
        1.ReLU
        2.Tanh
        3.Linear
        4.Threshold
        5.PiecewiseLinear
        6.Sigmoid
*/
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

static float ActivateFunctionThreshold(float input){

    if(input < 0)
        return 0;
    else if(input >= 0)
            return 1;

}

static float ActivationFunctionPL(float input){

    if(input >= 0.5)
        return 1;
    else if(input < 0.5 && input > -0.5)
            return input;
        else if(input <= -0.5)
                return 0;

}

static float ActivationFunctionSigmoid(float input){

    return (float)(1/(1 + exp(SLOPE_PARAMETER * input)));

}


/*
    Pointer Array function to hold the Actiavtion functions
*/
static float(*ActivationFUnction[])(float) = {

    ActivationFunctionReLU,
    ActivationFunctionTanh,
    ActivationFunctionLinear,
    ActivateFunctionThreshold,
    ActivationFunctionPL,
    ActivationFunctionSigmoid,

};

/*

    Setting the input variable of the _perceptron
*/

static void _FeedForward(float input[],float weights[],int size,_perceptron * p){

    if(p->input == NULL)
        p->input = (float *)calloc(size,sizeof(float));
    
    for(int i = 0;i < size;i++){
        p->input[i] = input[i] * weights[i];
    }
        
    
    p->size = size;

}

/*
    set the _perceptron's pointer to null as to avoid segmentation fault
*/
static void Set_perceptronPointers(_perceptron * p){

    p->input = NULL;

}

/*
    Free the _perceptron pointer
*/
static void _FreePerceptron(_perceptron * p){

    free(p->input);

}

/*
    Return the Output for computation/Algorithim
*/
static float _GetOutput(_perceptron * p){
    return p->output;
}

static void _SummingFunction(_perceptron * p,float bias){

    int size = p->size;
    float output = bias;

    for(int i = 0;i < size;i++){
        output += p->input[i];
    }

    p->output = output;

}

/*
    Set the Activation Function index to choose which activation is to be used
*/
static void _SetActivationFunction(_perceptron * p,ActivationFunctionIndex index){

    if(index < TOTAL_NO_OF_ACTIVATIONFUNCIONS)
        p->index = index;
    else 
        p->index = UNDEFINED;

}

/*
    pass the output through the activatoin function
*/
static void _OutputFromActivationFunction(_perceptron * p){

    if(p->index == UNDEFINED){
        printf("ERROR : Undefined Actiation Function ! ");
        return;
    }

    p->output = (*ActivationFUnction[p->index])(p->output);
    
}

/*
    Init Perceptron
*/
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

void SetActivationFunction(Perceptron * instance,ActivationFunctionIndex index){

    _SetActivationFunction(instance->m_perceptron,index);

}

void OutputFromActivationFunction(Perceptron * instance){

    _OutputFromActivationFunction(instance->m_perceptron);

}


float GetOuput(Perceptron * instance){

    float output = _GetOutput(instance->m_perceptron);
    return output;
}

void FreePerceptron(Perceptron * instance){

    free(instance->input);
    free(instance->weights);
    _FreePerceptron(instance->m_perceptron);
    free(instance->m_perceptron);
    free(instance);

}








