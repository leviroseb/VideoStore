#ifndef NODOTIPO_H
#define NODOTIPO_H

template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *link;
};

#endif // NODOTIPO_H
