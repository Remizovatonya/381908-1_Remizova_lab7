#pragma once 

#include <fstream>
#include "TPtrListElem.h"
#include "TPtrListIter.h"
#include "iostream"

template <class T>
class TPtrList
{
protected:
    TPtrListElem<T>* root;
    TPtrListElem<T>* last;
    int count;
public:
    TPtrList();
    TPtrList(TPtrList<T>& _v);
    ~TPtrList();

    TPtrList<T>& operator =(TPtrList<T>& _v);

    void InsFirst(T d);
    void InsLast(T d);
    void Ins(TPtrListElem<T>* e, T d);

    bool IsEmpty(void) const;

    bool IsFull(void) const;

    int GetCount(void) const;

    TPtrListElem<T>* GetFirst();
    TPtrListElem<T>* GetLast();

    void DelFirst();
    void DelLast();
    void Del(TPtrListElem<T>* e);

    TPtrList<int>& multiplesToK(int k);

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TPtrList<T1>& A);
    template <class T1>
    friend istream& operator>> (istream& istr, TPtrList<T1>& A);

    static TPtrList<T>& load(const char* name);
    void save(const char* name);

    typedef TPtrListIter<T> iterator;
    iterator begin() {
        return TPtrListIter<T>(this->root);
    };
    iterator end() {
        return TPtrListIter<T>(this->last->GetNext());
    };
};


template <class T1>
ostream& operator<< (ostream& ostr, const TPtrList<T1>& A) {

    TPtrListElem<T1>* i = A.root;

    while (i != 0)
    {
        ostr << *i << endl;
        i = i->GetNext();
    }
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TPtrList<T1>& A) {
    int count;
    istr >> count;
    for (int i = 0; i < count; i++)
    {
        T1 d;
        istr >> d;
        A.InsLast(d);
    }
    return istr;
}

template<class T>
inline TPtrList<T>::TPtrList()
{
    this->root = 0;
    this->last = 0;
    this->count = 0;
}

template <class T>
TPtrList<T>::TPtrList(TPtrList<T>& _v)
{
    this->count = _v.count;

    TPtrListElem<T>* iter = _v.root;
    if (iter != 0) {
        auto* buffer = new TPtrListElem<T>(*iter);
        buffer->SetPrev(0);
        buffer->SetNext(0);
        this->root = buffer;

        TPtrListElem<T>* prev = buffer;
        iter = iter->GetNext();

        while (iter != 0) {
            buffer = new TPtrListElem<T>(*iter);

            buffer->SetNext(0);
            buffer->SetPrev(prev);
            prev->SetNext(buffer);

            prev = buffer;
            this->last = buffer;
            iter = iter->GetNext();
        }
    }
}
template <class T>
TPtrList<T>::~TPtrList()
{
    if (this->root != 0) {
        TPtrListElem<T>* prev = 0;
        while (this->root != 0) {
            prev = this->root;
            this->root = this->root->GetNext();
            delete prev;
        }
    }
    this->root = 0;
    this->last = 0;
    this->count = 0;
}

template <class T>
TPtrList<T>& TPtrList<T>::operator =(TPtrList<T>& _v)
{
    if (this == &_v)
        return *this;

    this->count = _v.count;

    if (this->root != 0) {
        TPtrListElem<T>* prev = 0;
        while (this->root != 0) {
            prev = this->root;
            this->root = this->root->GetNext();
            delete prev;
        }
    }

    TPtrListElem<T>* iter = _v.root;
    if (iter != 0) {
        auto* buffer = new TPtrListElem<T>(*iter);
        buffer->SetPrev(0);
        buffer->SetNext(0);
        this->root = buffer;

        TPtrListElem<T>* prev = buffer;
        iter = iter->GetNext();

        while (iter != 0) {
            buffer = new TPtrListElem<T>(*iter);

            buffer->SetNext(0);
            buffer->SetPrev(prev);
            prev->SetNext(buffer);

            prev = buffer;
            this->last = buffer;
            iter = iter->GetNext();
        }
    }
    return *this;
}

template<class T>
inline void TPtrList<T>::InsFirst(T d)
{
    TPtrListElem<T>* elem = new TPtrListElem<T>(d);
    elem->SetNext(this->root);
    if (this->root != 0)
        this->root->SetPrev(elem);
    elem->SetPrev(0);
    this->root = elem;
    this->count++;
    if (this->last == 0)
        this->last = elem;
}

template<class T>
inline void TPtrList<T>::InsLast(T d)
{
    auto* elem = new TPtrListElem<T>(d);
    elem->SetNext(0);
    elem->SetPrev(this->last);
    if (this->last != 0)
        this->last->SetNext(elem);
    this->last = elem;
    this->count++;
    if (this->root == 0)
        this->root = elem;
}

template<class T>
inline void TPtrList<T>::Ins(TPtrListElem<T>* e, T d)
{
    auto* elem = new TPtrListElem<T>(d);
    elem->SetNext(e->GetNext());
    elem->SetPrev(e);
    e->GetNext()->SetPrev(elem);
    e->SetNext(e);
    count++;
}

template<class T>
inline bool TPtrList<T>::IsEmpty(void) const
{
    return this->count == 0;
}

template<class T>
inline bool TPtrList<T>::IsFull(void) const
{
    try
    {
        auto* tmp = new TPtrListElem<T>(0);
        delete tmp;
        return false;
    }
    catch (...)
    {
        return true;
    }
}


template<class T>
inline TPtrListElem<T>* TPtrList<T>::GetFirst()
{
    return this->root;
}

template<class T>
inline TPtrListElem<T>* TPtrList<T>::GetLast()
{
    return this->last;
}

template<class T>
inline void TPtrList<T>::DelFirst()
{
    auto* elem = this->root;
    this->root = this->root->GetNext();
    delete elem;
    this->count--;
}

template<class T>
inline void TPtrList<T>::DelLast()
{
    auto* elem = this->last;
    this->last = this->last->GetPrev;
    delete elem;
    this->count--;
}

template<class T>
inline void TPtrList<T>::Del(TPtrListElem<T>* e)
{
    e->GetNext()->SetPrev(e->GetPrev());
    e->GetPrev()->SetNext(e->GetNext());
    count--;
    delete e;
}

template<class T>
inline int TPtrList<T>::GetCount() const
{
    return this->count;
}

template<class T>
TPtrList<T>& TPtrList<T>::load(const char* name) {
    std::ifstream file;
    file.open(name, std::fstream::in);
    if (!file.is_open())
        throw "Cant open such file";
    int size;
    file >> size;
    auto* list = new TPtrList();
    file >> *list;
    file.close();
    return *list;
}

template<class T>
void TPtrList<T>::save(const char* name) {
    fstream file;
    file.open(name, fstream::out);
    if (!file.is_open())
        throw "Cant open such file";
    file << this->count << "\n" << *this;
    file.close();
}

template<class T>
TPtrList<int>& TPtrList<T>::multiplesToK(int k) {
    auto* c = new TPtrList();
    iterator i = this->begin();
    while (this->end() != i) {
        if (*i % k == 0) {
            c->InsLast(*i);
        }
        i++;
    }
    return *c;
}


