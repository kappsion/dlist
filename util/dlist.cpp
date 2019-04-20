#include "common.h"
#include "dlist.h"

kdp::dlist::dlist()
{
    _front = _rear = nullptr;
    _size = 0;
}

void kdp::dlist::add_front(kdp::dlist::cetype &rhs)
{
    element *e = new element;
    if (!e)
        throw "new fail!";
    e->val = rhs;
    
    if (_size == 0)
    {
        e->pre = e->nxt = nullptr;
        _front = _rear = e;
    }
    else
    {
        e->pre = nullptr;
        e->nxt = _front;

        _front->pre = e;
        _front = e;
    }

    ++_size;
}

void kdp::dlist::add_rear(kdp::dlist::cetype &rhs)
{
    element *e = new element;
    if (!e)
        throw "new fail!";
    e->val = rhs;

    if (_size == 0)
    {
        e->pre = e->nxt = nullptr;
        _front = _rear = e;
    }
    else
    {
        _rear->nxt = e;
        e->pre = _rear;
        e->nxt = nullptr;
        _rear = e;
    }

    ++_size;
}

void kdp::dlist::add_after(kdp::dlist::cetype &rhs, kdp::dlist::cetype &to)
{
    kdp::dlist::itr i = _front;
    while (i && i->val != to) i = i->nxt;
    if (!i) add_rear(rhs);
    else
    {
        element *e = new element;
        if (!e)
            throw "new fail";
        e->val = rhs;
        e->nxt = i->nxt;
        e->pre = i;
        if (i->nxt) i->nxt->pre = e;
        else _rear = e;
        i->nxt = e;
    }

    ++_size;
}

void kdp::dlist::add_before(kdp::dlist::cetype &rhs, kdp::dlist::cetype &to)
{
    kdp::dlist::itr i = _front;
    while (i && i->val != to) i = i->nxt;
    if (!i) add_front(rhs);
    else
    {
        element *e = new element;
        if (!e)
            throw "new fail";
        e->val = rhs;
        e->nxt = i;
        e->pre = i->pre;
        if (i->pre) i->pre->nxt = e;
        else _front = e;
        i->pre = e;
    }

    ++_size;
}

void kdp::dlist::remove(kdp::dlist::cetype &rhs)
{
    itr i = _front;
    while (i && i->val != rhs) i = i->nxt;
    if (!i) return;

    if (i == _front)
    {
        _front = i->nxt;
        if (i->nxt) i->nxt->pre = nullptr;
    }
    if (i == _rear)
    {
        _rear = i->pre;
        if (i->pre) i->pre->nxt = nullptr;
    }
    if (i != _front && i != _rear)
    {
        i->nxt->pre = i->pre;
        i->pre->nxt = i->nxt;
    }

    delete i;
    --_size;
}

void kdp::dlist::remove_front()
{
    itr i = _front;
    _front = i->nxt;
    if (i->nxt) i->nxt->pre = nullptr;
    if (i == _rear) _rear = nullptr;
    
    delete i;
    --_size;
}

void kdp::dlist::remove_rear()
{
    itr i = _rear;
    _rear = i->pre;
    if (i->pre) i->pre->nxt = nullptr;
    if (i == _front) _front = nullptr;

    delete i;
    --_size;
}

void kdp::dlist::remove_before(kdp::dlist::cetype &rhs)
{
    itr i = _front;
    while (i && i->val != rhs) i = i->nxt;
    if (!i || i == _front) return;

    itr tmp = i->pre;
    if (i->pre != _front)
    {
        i->pre->pre->nxt = i;
        i->pre = i->pre->pre;
    }
    else
    {
        _front = i;
        i->pre = nullptr;
    }

    delete tmp;
    --_size;
}

void kdp::dlist::remove_after(kdp::dlist::cetype &rhs)
{
    itr i = _front;
    while (i && i->val != rhs) i = i->nxt;
    if (!i || i == _rear) return;

    itr tmp = i->nxt;
    if (i->nxt != _rear)
    {
        i->nxt->nxt->pre = i;
        i->nxt = i->nxt->nxt;
    }
    else
    {
        _rear = i;
        i->nxt = nullptr;
    }

    delete tmp;
    --_size;
}

bool kdp::dlist::is_exist(kdp::dlist::cetype &rhs)
{
    for (itr i = _front; i; i = i->nxt)
        if (i->val == rhs) return true;
    return false;
}

void kdp::dlist::remove_all()
{
    if (_size == 0) return;
    
    for (itr i = _front->nxt; i; i = i->nxt)
        delete i->pre;
    delete _rear;

    _size = 0;
    _front = _rear = nullptr;
}

kdp::dlist::~dlist()
{
    remove_all();
}
