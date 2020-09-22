#pragma once

#include "Processor.h"

namespace DiffProcessor
{
    Processor::Processor(long limit)
    {
        // TODO: initialization.
    }
    Processor::~Processor()
    {
        // TODO: Free resources.
    }

    void Processor::do_process(SortedLimitedList<double> &must_be_equal_to,
            const SortedLimitedList<double> &expected_output) {

        remove_elements(must_be_equal_to, expected_output);
        merge_elements(must_be_equal_to, expected_output);
    }

    void Processor::remove_elements(SortedLimitedList<double> &must_be_equal_to,
            const SortedLimitedList<double> &expected_output) {

        auto current_expected_iterator = expected_output.first();
        for (auto current_iterator = must_be_equal_to.first();
            current_iterator != must_be_equal_to.end(); ) {

            while(current_expected_iterator != expected_output.end()
                && *current_expected_iterator < *current_iterator) current_expected_iterator++;

            if (current_expected_iterator == expected_output.end() || *current_expected_iterator > *current_iterator) {
                auto next_iterator = current_iterator;
                next_iterator++;

                must_be_equal_to.remove(current_iterator);

                current_iterator = next_iterator;

            }else {
                current_iterator++;
                current_expected_iterator++;
            }
        }
    }

    void Processor::merge_elements(SortedLimitedList<double> &must_be_equal_to,
                                    const SortedLimitedList<double> &expected_output) {

        auto current_iterator = must_be_equal_to.first();
        auto current_expected_iterator = expected_output.first();

        while(current_iterator != must_be_equal_to.end() && current_expected_iterator != expected_output.end()) {
            if (*current_expected_iterator < *current_iterator) {
                must_be_equal_to.add_before(current_iterator, *current_expected_iterator);
            }else {
                current_iterator++;
            }

            current_expected_iterator++;
        }

        while(current_expected_iterator != expected_output.end()) {
            must_be_equal_to.add_last(*current_expected_iterator);
            current_expected_iterator++;
        }

    }
};