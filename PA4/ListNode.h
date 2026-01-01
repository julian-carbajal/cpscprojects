/**
 * @file ListNode.h
 * @brief Template class for a doubly-linked list node.
 * 
 * This is the FOUNDATION (Layer 1) of the data structure hierarchy:
 * 
 * ARCHITECTURE:
 *   ListNode (You are here) - Individual node with data and prev/next pointers
 *       ^
 *       |
 *   DblList - Doubly-linked list using ListNode
 *       ^
 *       |
 *   ListQueue - Queue built on top of DblList
 *       ^
 *       |
 *   Office - Uses ListQueue to manage customer waiting lines
 * 
 * @author Julian Carbajal
 * @date Spring 2024
 */

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <exception>

using namespace std;

/**
 * @class ListNode
 * @brief A node in a doubly-linked list containing data and pointers to adjacent nodes.
 * 
 * @tparam T The type of data stored in the node.
 */
template <class T>
class ListNode
{
public:
    /**
     * @brief Default constructor - creates an empty node with null pointers.
     */
    ListNode();

    /**
     * @brief Parameterized constructor - creates a node with the given data.
     * @param d The data to store in this node.
     */
    ListNode(T d);

    /**
     * @brief Destructor - cleans up the node.
     */
    ~ListNode();

    ListNode *next;  ///< Pointer to the next node in the list
    ListNode *prev;  ///< Pointer to the previous node in the list
    T data;          ///< The data stored in this node
};

/**
 * @brief Default constructor implementation.
 */
template <class T>
ListNode<T>::ListNode()
{
    next = NULL;
    prev = NULL;
}

/**
 * @brief Parameterized constructor implementation.
 * @param d The data to store.
 */
template <class T>
ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL;
    prev = NULL;
}


/**
 * @brief Destructor implementation - nullifies pointers.
 */
template <class T>
ListNode<T>::~ListNode()
{
    next = NULL;
    prev = NULL;
}
#endif
