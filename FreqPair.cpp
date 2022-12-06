//
// Created by 浮生似流年 on 2022/11/29.
//

#include "FreqPair.h"


    template <class Elem>
    FreqPair<Elem>::FreqPair(Elem s, int f)
    {symbol = s; freq = f;}
    template <class Elem>
    int FreqPair<Elem>::weight() {return freq;}
    template <class Elem>
    Elem FreqPair<Elem>::val() {return symbol;}

// std