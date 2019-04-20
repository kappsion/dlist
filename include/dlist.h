#ifndef __DLIST_H__
#define __DLIST_H__

namespace kdp{

    class dlist{
        public:

            typedef int T;
            using etype = T;
            using cetype = const T;

            typedef struct s_e{
                etype val;
                struct s_e *pre, *nxt;
            }element;
            using celement = const element;
            using itr = element *;
            using citr = const element *;

            dlist();
            ~dlist();
            dlist(const size_t rhs);
            void add_front(cetype &rhs);
            void add_rear(cetype &rhs);
            void add_before(cetype &rhs, cetype &to);
            void add_after(cetype &rhs, cetype &to);
            void remove_front();
            void remove_rear();
            void remove_before(cetype &rhs);
            void remove_after(cetype &rhs);
            void remove(cetype &rhs);
            void remove_all();
            bool is_exist(cetype &rhs);
            size_t size()const { return _size; }

            citr begin()const{ return _front; }
            citr rbegin()const{ return _rear; }
            
        private:
            itr _rear, _front;
            size_t _size;
    };
}

#endif
