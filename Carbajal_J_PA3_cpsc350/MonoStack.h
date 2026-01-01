/**
 * @file MonoStack.h
 * @brief Template class for a monotonic stack data structure.
 * 
 * A monotonic stack maintains elements in either strictly increasing
 * or strictly decreasing order. Used in this project to efficiently
 * determine which people can see the speaker.
 * 
 * ARCHITECTURE:
 *   MonoStack (You are here) - Stack data structure
 *       ^
 *       |
 *   SpeakerView - Uses stack to process visibility
 *       ^
 *       |
 *   main.cpp - Entry point
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/**
 * @class MonoStack
 * @brief A stack that can maintain monotonic order.
 * @tparam T The type of elements stored.
 */
template <typename T>
class MonoStack
{
public:
    /** @brief Default constructor. */
    MonoStack();
    
    /** @brief Constructor with size and direction. @param iSize Initial capacity. @param monotonicDirection 'd' for descending. */
    MonoStack(int iSize, char monotonicDirection);
    
    /** @brief Destructor - frees array. */
    ~MonoStack();
    
    /** @brief Get number of elements. @return Current size. */
    int size();
    
    /** @brief Check if stack is empty. @return True if empty. */
    bool isEmpty();
    
    /** @brief Push element onto stack. @param c Element to push. */
    void push(T c);
    
    /** @brief Pop and return top element. @return Top element. */
    T pop();
    
    /** @brief View top element without removing. @return Top element. */
    T peek();
    
    /** @brief Get underlying array. @return Pointer to array. */
    T *getStackArr();
    
    /** @brief Get top index. @return Top index. */
    int getTopCount();

private:
    T *stackArr;              ///< Dynamic array for storage
    int count;                ///< Number of elements
    int max;                  ///< Current capacity
    int top;                  ///< Index of top element
    char monotonicDirection;  ///< 'd' for descending
    bool isFull();            ///< Check if at capacity
};

template <typename T>
MonoStack<T>::MonoStack()
{
    top = -1;
    count = 0;
    max = 0;
    stackArr = NULL;
}

template <typename T>
MonoStack<T>::MonoStack(int iSize, char monotonicDirection)
{
    top = -1;
    count = 0;
    max = iSize;
    this->monotonicDirection = monotonicDirection;
    stackArr = new T[max];
}

template <typename T>
MonoStack<T>::~MonoStack()
{
    delete[] stackArr;
}

template <typename T>
int MonoStack<T>::size()
{
    return count;
}

template <typename T>
bool MonoStack<T>::isEmpty()
{
    return (count == 0);
}

template <typename T>
bool MonoStack<T>::isFull()
{
    return (count == max);
}

template <typename T>
void MonoStack<T>::push(T c){
    if (isFull())
    {
        T *temp = new T[2 * max];
        for (int i = 0; i < max; ++i)
        {
            temp[i] = stackArr[i];
        }
        max*= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    stackArr[++top] = c;
    ++count;
}

template <typename T>
T MonoStack<T>::pop()
{
    --count;
    return stackArr[top--];
}

template <typename T>
T MonoStack<T>::peek()
{
    return stackArr[top];
}

template <typename T>
T *MonoStack<T>::getStackArr()
{
    return stackArr;
}

template <typename T>
int MonoStack<T>::getTopCount()
{
    return top;
}


#endif