#include "common.h"
#include "dlist.h"
#include <bits/stdc++.h>

using namespace std;

void rpall(const kdp::dlist &dl)
{
    cout << "dl size " << dl.size() << ", elements:" << endl;
    for (auto i = dl.rbegin(); i; i = i->pre)
        cout << "\t" << i->val;
    cout << endl;
}

void pall(const kdp::dlist &dl)
{
    cout << "dl size " << dl.size() << ", elements:" << endl;
    for (auto i = dl.begin(); i; i = i->nxt)
        cout << "\t" << i->val;
    cout << endl;

    rpall(dl);
}

int main()
{
    kdp::dlist dl;
    
    // add
    {
        for (int i = 0; i < 10; ++i)
            dl.add_rear(i + 1);
        pall(dl);
        dl.add_before(4, 3);
        dl.add_after(11, 10);
        dl.add_front(-1);
        dl.add_rear(100);
        pall(dl);
    }

    // remove
    {
        dl.remove(5);
        dl.remove(4);
        dl.remove_front();
        dl.remove_rear();
        dl.remove_before(11);
        dl.remove_after(9);
        pall(dl);
    }

    // find
    {
        cout << dl.is_exist(1) << endl;
        cout << dl.is_exist(3) << endl;
        cout << dl.is_exist(100) << endl;
        cout << dl.is_exist(-1) << endl;
        pall(dl);
    }

    // remove all
    {
        dl.remove_all();
 //       pall(dl);
    }

    return 0;
}
