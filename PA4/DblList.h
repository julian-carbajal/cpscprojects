/**
 * @file DblList.h
 * @brief Template class for a doubly-linked list.
 * 
 * This is Layer 2 of the data structure hierarchy:
 * 
 * ARCHITECTURE:
 *   ListNode - Individual node with data and prev/next pointers
 *       ^
 *       |
 *   DblList (You are here) - Doubly-linked list using ListNode
 *       ^
 *       |
 *   ListQueue - Queue built on top of DblList
 *       ^
 *       |
 *   Office - Uses ListQueue to manage customer waiting lines
 * 
 * The DblList provides O(1) insertion/removal at both ends, making it
 * ideal for implementing a queue data structure.
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef DblList_H
#define DblList_H

#include "ListNode.h"

/**
 * @class DblList
 * @brief A doubly-linked list supporting operations at both ends.
 * 
 * @tparam T The type of data stored in the list.
 */
template <typename T>
class DblList
{
private:
    ListNode<T> *front;   ///< Pointer to the first node
    ListNode<T> *back;    ///< Pointer to the last node
    unsigned int size;    ///< Number of elements in the list

public:
    /** @brief Default constructor - creates an empty list. */
    DblList<T>();
    
    /** @brief Destructor - removes all nodes and frees memory. */
    ~DblList<T>();

    /** @brief Insert data at the front of the list. @param d Data to insert. */
    void insertFront(T d);
    
    /** @brief Insert data at the back of the list. @param d Data to insert. */
    void insertBack(T d);
    
    /** @brief Remove and return data from the front. @return The data from the front node. */
    T removeFront();
    
    /** @brief Remove and return data from the back. @return The data from the back node. */
    T removeBack();
    
    /** @brief Remove a node by value. @param value Value to find and remove. @return Index of removed node. */
    int removeNode(int value);
    
    /** @brief Find a value in the list. @param value Value to search for. @return Index if found, 0 otherwise. */
    T find(int value);
    
    /** @brief Get element at a specific position. @param pos 0-indexed position. @return Data at that position. */
    T get(int pos);
    
    /** @brief Check if the list is empty. @return True if empty, false otherwise. */
    bool isEmpty();
    
    /** @brief Get the number of elements. @return Size of the list. */
    unsigned int getSize();
    
    /** @brief Apply a function to each element. @param func Function pointer to apply. */
    void forEach(void (*func)(T));

    /** @brief Print the list contents. @param printLink If true, also print node addresses. */
    void printList(bool printLink);
};


template <class T>
DblList<T>::DblList(){
    front = nullptr;
    back = nullptr;
    size = 0;
}

template <class T>
DblList<T>::~DblList(){
    while(!isEmpty()){
        removeFront();

    }
}

template <class T>
void DblList<T>::insertFront(T d){
    ListNode<T> *newNode = new ListNode<T>(d);
    if(isEmpty()){
        back = newNode;
    } else {
        front->prev = newNode;
    }
    newNode->next = front;
    front = newNode;
    size++;
}

template <class T>
void DblList<T>::insertBack(T d){
    
    ListNode<T> *newNode = new ListNode<T>(d);
    if(isEmpty()){
        front = newNode;
    } else {
        back->next = newNode;
    }
    newNode->prev = back;
    back = newNode;
    size++;

}

template <class T>
T DblList<T>::removeFront(){
    if(isEmpty()){
        throw std::exception();
    }
    T d = front->data;
    ListNode<T> *temp = front;
    front = front->next;
    if(!front){
        back = nullptr;
    } else {
        front->prev = nullptr;
    }
    delete temp;
    size--;
    return d;

}

template <class T>
T DblList<T>::removeBack(){
    
    if(isEmpty()){
        throw std::exception();
    }
    T d = back->data;
    ListNode<T> *temp = back;
    back = back->prev;
    if(!back){
        front = nullptr;
    } else {
        back->next = nullptr;
    }
    delete temp;
    size--;
    return d;
}

template <class T>
int DblList<T>::removeNode(int value){

    if(isEmpty()){
        throw std::exception();
    }
}

template <class T>
T DblList<T>::find(int value){
    
    int idx = 0;
    ListNode<T> *curr = front;
    while(curr != nullptr){
        ++idx;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }
    if(curr == nullptr){
        idx = 0;
    }
    return idx;
}

template <class T>
T DblList<T>::get(int pos){
    if(pos < 0 || pos >= size){
        throw std::runtime_error("Index out of bounds");
    }
    ListNode<T> *curr = front;
    for(int i = 0; i < pos; i++){
        curr = curr->next;
    }
    return curr->data;
}

template <class T>
bool DblList<T>::isEmpty(){
    return size == 0;
}

template <class T>
void DblList<T>::forEach(void (*func)(T)){
    ListNode<T> *curr = front;
    while(curr != nullptr){
        func(curr->data);
        curr = curr->next;
    }
}

template <class T>
unsigned int DblList<T>::getSize(){

    return size;
}

template <class T>
void DblList<T>::printList(bool printLink){

    ListNode<T> *curr = front;
    while(curr != nullptr){
        cout << curr->data << " ";
        if(printLink){
            cout << curr << " ";
        }
        curr = curr->next;
    }
    cout << endl;
}
#endif