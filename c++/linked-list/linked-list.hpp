/**
 * Author: Jacob Rice
 * Description: linked-list header
 * Date: 01/23/2024
*/
#include <initializer_list>
using namespace std;

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

/* linked list class */
template <typename T>
class LinkedList
{
    public:
        Node<T>* head;
        Node<T>* tail;
        int count;

        // default
        LinkedList()
        {
            this->head = NULL;
            this->tail = NULL;
            this->count = 0;
        }

        // parameterized
        LinkedList(initializer_list<T> args)
        {
            size_t argc = args.size();
            this->head = new Node(args[0]);

            if(argc > 1)
            {
                // link the rest of the stuff in args
            }
        }

        // other funcs here

        int size() { return count; }
};

/* node class */
template <typename T>
class Node
{
    public:
        T data;
        Node* next;

        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};

#endif