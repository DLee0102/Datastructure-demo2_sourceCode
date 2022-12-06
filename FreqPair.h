//
// Created by 浮生似流年 on 2022/11/29.
//

#ifndef MAIN_CPP_FREQPAIR_H
#define MAIN_CPP_FREQPAIR_H


    template <class Elem>
    class FreqPair {
            private:
                Elem symbol;
                int freq;
            public:
                FreqPair(Elem s, int f);
                int weight();
                Elem val();
    };



#endif //MAIN_CPP_FREQPAIR_H
