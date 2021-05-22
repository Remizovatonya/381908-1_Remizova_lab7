#pragma once

#include <iosfwd>

using namespace std;

template <class T>
class TPtrListElem
{
protected:
    T data;
    TPtrListElem* next;
    TPtrListElem* prev;
public:
    TPtrListElem(T _data);
    ~TPtrListElem();

    T GetData();
    TPtrListElem* GetNext();
    TPtrListElem* GetPrev();

    void SetData(T _data);
    void SetNext(TPtrListElem* _next);
    void SetPrev(TPtrListElem* _prev);

    bool operator==(TPtrListElem& _elem);
    bool operator!=(TPtrListElem& _elem);


    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TPtrListElem<T1>& A);
    template <class T1>
    friend istream& operator >> (istream& istr, TPtrListElem<T1>& A);
};


template<class T1>
inline ostream& operator<<(ostream& ostr, const TPtrListElem<T1>& A)
{
    ostr << A.data;
    return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TPtrListElem<T1>& A)
{
    istr >> A.data;
    return istr;
}


template<class T>
inline TPtrListElem<T>::TPtrListElem(T _data)
{
    data = _data;
    next = 0;
    prev = 0;
}

template<class T>
inline TPtrListElem<T>::~TPtrListElem()
{
    next = 0;
    prev = 0;
}

template<class T>
inline T TPtrListElem<T>::GetData()
{
    return data;
}

template<class T>
inline TPtrListElem<T>* TPtrListElem<T>::GetNext()
{
    return next;
}

template<class T>
inline TPtrListElem<T>* TPtrListElem<T>::GetPrev()
{
    return prev;
}

template<class T>
inline void TPtrListElem<T>::SetData(T _data)
{
    data = _data;
}

template<class T>
inline void TPtrListElem<T>::SetNext(TPtrListElem<T>* _next)
{
    next = _next;
}

template<class T>
inline void TPtrListElem<T>::SetPrev(TPtrListElem<T>* _prev)
{
    prev = _prev;
}

template<class T>
bool TPtrListElem<T>::operator==(TPtrListElem& _elem) 
{
    return this->GetData() == _elem.GetData();
}

template<class T>
bool TPtrListElem<T>::operator!=(TPtrListElem& _elem) 
{
    return this->GetData() != _elem.GetData();
}


