#include<iostream>

using namespace std;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * /
* 
*          fun(3)-----------------------------------------------------
*          /    \                                                     \
*   print(3)     fun(2)----------------------------                    fun(2)
*                /     \                           \                   /     \
*         print(2)      fun(1)-----           fun(1)           print(2)      fun(1)
*                       /     \    *         /      \                 /      \
*                print(1)      fun(0) print(1)       fun(0)    print(1)      func(0)
*                                 |                     |                      |
*                                 *                     *                      *
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void fun(int n) {
    if (n > 0) {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    // time O(2 ^ n)
    // space O(n)
    fun(3);

    return 0;
}