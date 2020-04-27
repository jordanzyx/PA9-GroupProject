/*******************************************************************************************
* Programmer: Jordan Muehlbauer *
* Class: CptS 122, Spring, 2020;
* Programming Assignment: PA5 *
* Date: March 27th, 2020 *
* Description: This file defines and implements a stack of any generic type T
*******************************************************************************************/
#ifndef CPTS122PA5_QUEUE_H
#define CPTS122PA5_QUEUE_H

/*
 * QNODE CLASS DEFINITION
 */
template <class T>
class QNode {
private:
    T data;
    QNode<T> *behind = nullptr;
public:
	QNode<T>();
    QNode<T> *getBehind();
    T getData();
    void setData(T update);
    void setBehind(QNode<T> *next);
};
/*
 *
 * INLINE QNODE<T> FUNCTIONS
 *
 */
template<class T>
QNode<T>::QNode<T>()
{

}
template<class T>
QNode<T> *QNode<T>::getBehind() {
    return behind;
}

template<class T>
T QNode<T>::getData() {
    return data;
}

template<class T>
void QNode<T>::setData(T update) {
    this->data = update;
}

template<class T>
void QNode<T>::setBehind(QNode<T> *next) {
    behind = next;
}
/*
 *
 * STACK CLASS DEFINTION
 *
 */
template <class T>
class Queue{
private:
    QNode<T> *head = nullptr;
public:
    QNode<T>* getHead();
    void setHead(QNode<T> *newHead);
    void push(T item);
    T top();
    void pop();
    bool empty();
};

template<class T>
void Queue<T>::push(T item) {
    //Allocate space for the new node
    QNode<T> *newNode = new QNode<T>;
    newNode->setData(item);
    newNode->setBehind(nullptr);

    //If the queue is empty put it at the top
    if(empty()){
        setHead(newNode);
        return;
    }

    //Otherwise go to the end node and make sure that the end node points to this node
    QNode<T> *current = head;
    while (current->getBehind() != nullptr){
        //Go to the next node
        current = current->getBehind();
    }

    //Insert the node
    current->setBehind(newNode);
}

template<class T>
T Queue<T>::top() {
    return head->getData();
}

//Get the top node so we can iterate through the queue


template<class T>
void Queue<T>::pop() {
    //If Empty return
    if(empty())return;

    //Set the head to node behind it
    QNode<T> *toDelete = head;
    setHead(head->getBehind());

    //Delete the old head
    delete toDelete;
}

template<class T>
bool Queue<T>::empty() {
    return head == nullptr;
}

template<class T>
void Queue<T>::setHead(QNode<T> *newHead) {
    head = newHead;
}

template<class T>
QNode<T> *Queue<T>::getHead() {
    return head;
}


#endif //CPTS122PA5_QUEUE_H