/**
 * @file ListQueue.h
 * @brief Template class for a queue implemented using a doubly-linked list.
 * 
 * This is Layer 3 of the data structure hierarchy:
 * 
 * ARCHITECTURE:
 *   ListNode - Individual node with data and prev/next pointers
 *       ^
 *       |
 *   DblList - Doubly-linked list using ListNode
 *       ^
 *       |
 *   ListQueue (You are here) - Queue built on top of DblList
 *       ^
 *       |
 *   Office - Uses ListQueue to manage customer waiting lines
 * 
 * QUEUE BEHAVIOR:
 * - FIFO (First In, First Out)
 * - add() inserts at the back
 * - remove() removes from the front
 * - Used to simulate customers waiting in line at each office
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef ListQueue_H
#define ListQueue_H
#include <iostream>
#include "DblList.h"

/**
 * @class ListQueue
 * @brief A FIFO queue implemented using DblList.
 * 
 * @tparam T The type of data stored in the queue.
 */
template <typename T>
class ListQueue
{
public:
    /** @brief Default constructor - creates an empty queue. */
    ListQueue();
    
    /** @brief Virtual destructor - frees the underlying list. */
    virtual ~ListQueue();
    
    /** @brief Add data to the back of the queue. @param data Data to enqueue. */
    void add(T data);
    
    /** @brief Remove and return data from the front. @return Data from the front. */
    T remove();
    
    /** @brief View the front element without removing it. @return Data at the front. */
    T peek();
    
    /** @brief Check if the queue is empty. @return True if empty. */
    bool isEmpty();
    
    /** @brief Get the number of elements in the queue. @return Queue size. */
    int size();
    
    /** @brief Apply a function to each element (used to increment wait times). @param func Function to apply. */
    void forEach(void (*func)(T));

private:
    DblList<T> *m_list;  ///< The underlying doubly-linked list
};

template <typename T>
ListQueue<T>::ListQueue()
{
    m_list = new DblList<T>();
}

template <typename T>
ListQueue<T>::~ListQueue()
{
    delete m_list;
}

template <typename T>
bool ListQueue<T>::isEmpty()
{
    return (m_list->getSize() == 0);
}

template <typename T>
int ListQueue<T>::size()
{
    return m_list->getSize();
    ;
}

template <typename T>
void ListQueue<T>::add(T data)
{
    m_list->insertBack(data);
}

template <typename T>
T ListQueue<T>::remove()
{
    return m_list->removeFront();
}

template <typename T>
T ListQueue<T>::peek()
{
    return m_list->get(0);
}

template <typename T>
void ListQueue<T>::forEach(void (*func)(T))
{
    m_list->forEach(func);
}

#endif