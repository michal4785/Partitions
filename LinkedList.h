//
// Created by michal on 01.06.22.
//

#ifndef PARTITIONS_LINKEDLIST_H
#define PARTITIONS_LINKEDLIST_H

#include "Element.h"
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
public:
    LinkedList(){
        this->length = 0;

    }
    LinkedList(const LinkedList<T>& list){
    }
    void append(T value){
        auto * element =  new Element<T>(value);
        if(length == 0){
            head = element;
            lastElement = head;
            head->setPreviousElement(lastElement);
            head->setNextElement(head);


        }
        else{
            lastElement->setNextElement(element);
            element->setPreviousElement(lastElement);
            lastElement = element;
            lastElement->setNextElement(head);
            head->setPreviousElement(lastElement);


        }
        length++;

    }
    Element<T> pop(){
        if(length == 0){
            throw std::runtime_error("List is empty!");

        }
        else if(length == 1){
            Element<T> element = *lastElement;
            delete head;
            length--;
            return element;


        }
        else{
            Element<T> element = *lastElement;
            lastElement = lastElement->getPreviousElement();
            delete lastElement->getNextElement();
            length--;
            return element;


        }

    }
    Element<T> pop(int index){
        if(index < 0 || index >= length ){
            throw std::runtime_error("Index out of range!");

        }
        else if(length == 0){
            throw std::runtime_error("List is empty!");

        }
        else if(index == length - 1){
            return pop();

        }
        else if(index == 0){
            Element<T> element = *head;
            head = head->getNextElement();
            delete head->getPreviousElement();
            length--;
            return element;

        }
        else if(length == 1){
            Element<T> element = *lastElement;
            delete head;
            length--;
            return element;


        }
        else{
            Element<T> element = *getElement(index);
            Element<T> * previous = element.getPreviousElement();
            Element<T> * next = element.getNextElement();
            previous->setNextElement(next);
            next->setPreviousElement(previous);
            delete getElement(index);
            length--;
            return element;


        }

    }
    Element<T> * getElement(int index){
        if(length == 0){
            throw std::runtime_error("List is empty!");

        }
        else{
            Element<T> * currentElement = head;
            int i = 0;
            while(i != index && i < length){
                currentElement = currentElement->getNextElement();
                i++;

            }
            if(i < length){
                return currentElement;


            }
            else{
                throw std::runtime_error("There is not such element in the list!");


            }


        }

    }
    T get(int index){
        return getElement(index)->getValue();

    }
    void replace(int index, T value){
        if(index < 0 || index >= length ){
            throw std::runtime_error("Index out of range!");

        }
        else{
            this->getElement(index)->setValue(value);

        }

    }
    void insert(int index, T value){
        if(index < 0 || index >= length ){
            throw std::runtime_error("Index out of range!");

        }
        if(index == length - 1){
            append(value);

        }
        else{
            Element<T> * current = this->getElement(index);
            Element<T> * previous = current->getPreviousElement();
            auto * element = new Element<T>(value);
            previous->setNextElement(element);
            element->setPreviousElement(previous);
            element->setNextElement(current);
            current->setPreviousElement(element);
            length++;

        }


    }
    int size() const{
        return length;

    }
    void swap(int i1, int i2){
        T temp = get(i1);
        replace(i1, get(i2));
        replace(i2, temp);

    }
    ~LinkedList(){
        while(length){
            pop();


        }

    }
    bool compare(LinkedList<T> * other){
        if(this->size() != other->size()){
            return false;

        }
        else{
            for (int i = 0; i < this->size(); ++i) {
                if(this->get(i) != other->get(i)){
                    return false;

                }

            }
            return true;

        }

    }

    friend ostream& operator<<(ostream& os, const LinkedList<T>& list);
private:
    Element<T> * head{

    };
    Element<T> * lastElement{

    };
    int length{
    };
};



template<class T>
ostream &operator<<(ostream& os, const LinkedList<T> & list)
{
    os<<'[';
    if(list.size() > 0){
        os<<list.get(0);

    }
    for (int i = 1; i < list.size(); ++i) {
        os<<", "<<list.get(i);

    }
    os<<']';
    return os;
}

#endif //PARTITIONS_LINKEDLIST_H
