// CaiDatHangDoiUuTien_C++.cpp

#include<algorithm>
#include<iostream>
using namespace std;
/*  Heap in C++
int a[] = { 423,72,57,45,84,847,59,596,706,026,62,26 };
    int n = sizeof(a) / sizeof(int);

    make_heap(a, a + n);    // Tạo heap
    cout << "\nHeap:";
    for (auto x : a)
        cout << x << " ";
*/


template<class T, class cmp = less<T> >
class PQ    // Priority Queue
{
    int n, cap; // n - size;    
    T* buf;     // Mang chua du lieu
    cmp ss;
    public:
        PQ() { n = cap = 0; buf = null; }
        int size() { return n; }
        bool empty(){return n==0}
        void push(T x)
        {
            if (n == cap)
            {
                cap = cap * 2 + 1;
                T *tem = new T[cap];
                for (int i = 0;i < n;i++)
                    tem[i] = buf[i];
                if (buf) delete[]buf;
                buf = tem;
            }

            buf[n++] = x;
            int p = n - 1;
            while (p > 0 && ss(buf[(p - 1) / 2] , buf[p]))
            {
                swap(buf[(p - 1) / 2], buf[p]);
                p = (p - 1) / 2;
            }
        }

        T top() { return buf[0]; }

        void pop()
        {
            if (n == 1)
            {
                n--;
                return;
            }
            buf[0] = buf[--n];
            heapy(0);
        }

        private void heapy(int k)
        {
            if (2 * k + 1 >= n) return;
        }

};
int main()
{
    
}
