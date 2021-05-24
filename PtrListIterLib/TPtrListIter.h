#pragma once

#include "TPtrListElem.h"
#include "iostream"

template <class T>
class TPtrListIter
{
private:
    TPtrListElem<T>* current;
public:

    T operator*(void);
    TPtrListIter<T>& operator++(int);
    TPtrListIter<T>& operator++();
    bool operator==(const TPtrListIter<T>& _iter);
    bool operator!=(const TPtrListIter<T>& _iter);

    explicit TPtrListIter(TPtrListElem<T>* elem);
    TPtrListIter(TPtrListIter<T> const& iterator);
    ~TPtrListIter() = default;
};

template<class T>
T TPtrListIter<T>::operator*() 
{
    return this->current->GetData();
}

template<class T>
TPtrListIter<T>& TPtrListIter<T>::operator++(int) 
{
    this->current = this->current->GetNext();
    return *this;
}

template<class T>
TPtrListIter<T>& TPtrListIter<T>::operator++() 
{
    this->current = this->current->GetNext();
    return *this;
}

template<class T>
bool TPtrListIter<T>::operator==(const TPtrListIter<T>& _iter)
{
    return this->current == _iter.current;
}
template<class T>
bool TPtrListIter<T>::operator!=(const TPtrListIter<T>& _iter) 
{
    return this->current != _iter.current;
}

template<class T>
TPtrListIter<T>::TPtrListIter(TPtrListIter<T> const& iterator) 
{
    this->current = new TPtrListElem<T>(*iterator.current);
}

template<class T>
TPtrListIter<T>::TPtrListIter(TPtrListElem<T>* elem) 
{
    this->current = elem;
}

