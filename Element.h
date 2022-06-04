//
// Created by michal on 01.06.22.
//

#ifndef PARTITIONS_ELEMENT_H
#define PARTITIONS_ELEMENT_H



template<class T>
class Element {
public:
    explicit Element(T value){
        this->value = value;

    }
    Element * getNextElement(){
        return this->nextElement;

    }
    Element * getPreviousElement(){
        return this->previousElement;

    }
    void setNextElement(Element * next){
        this->nextElement = next;

    }
    void setPreviousElement(Element * previous){
        this->previousElement = previous;

    }
    T getValue() const{
        return value;

    }
    void setValue(T newValue){
        this->value = newValue;

    }
private:
    T value;
    Element * nextElement{

    };
    Element * previousElement{

    };

};


#endif //PARTITIONS_ELEMENT_H
