#pragma once

using namespace std;

template <class N>
void swapElement(N &first, N &second)
{
    N temp = second;
    second = first;
    first  = temp;
}