#ifndef LISTAENLAZADAITERADOR_H
#define LISTAENLAZADAITERADOR_H
//#include <cstddef>
#include "nodeType.h"

template <class Type>
class linkedListIterator{
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type> *ptr);

    Type operator*();
    linkedListIterator<Type> operator++();

    bool operator==(const linkedListIterator<Type>& right) const;
    bool operator!=(const linkedListIterator<Type>& right) const;
private:
    nodeType<Type> *current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator(){
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr){
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*(){
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const{
    return (current != right.current);
}

#endif // LISTAENLAZADAITERADOR_H
