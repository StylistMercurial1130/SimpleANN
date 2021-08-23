#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

typedef struct _Perceptron _perceptron;

typedef struct{

//public
    float * input;
    float * weights;
    float bias;
    int size;
//private 
    void * m_perceptron;

}Perceptron;

typedef enum {

    RECTIFIED_LINEAR_ACTIVATION = 0,
    HYPERBOLIC_TANGENT = 1,
    LINEAR = 2,
    THRESHOLD = 3,
    PIECE_WISE_LINEAR = 4,
    SIGMOID = 5,
    UNDEFINED = -1

}ActivationFunctionIndex;

Perceptron * InitPerceptron();
void SetActivationFunction(Perceptron * instance,ActivationFunctionIndex index);
void OutputFromActivationFunction(Perceptron * instacnce);
void FreePerceptron(Perceptron * instance);
void FeedForward(float input[],float weights[],int size,float bias,Perceptron * perceptron);
void SummingFunction(Perceptron * instance);

#endif