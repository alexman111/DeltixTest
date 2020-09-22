#pragma once

#include "SortedLimitedList.h"

namespace DiffProcessor
{
    class Processor
    {
    public:
        explicit Processor(long limit);
        ~Processor();
        void do_process(SortedLimitedList<double> &must_be_equal_to, const SortedLimitedList<double> &expected_output);

    private:
        void remove_elements(SortedLimitedList<double> &must_be_equal_to,
                const SortedLimitedList<double> &expected_output);

        void merge_elements(SortedLimitedList<double> &must_be_equal_to,
                             const SortedLimitedList<double> &expected_output);
    };
}