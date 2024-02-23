#pragma once

#include <array>
#include <bit>
#include <cassert>

template <char char_to_find = ';'>
struct Finder
{
    static constexpr std::array<char, 8> mask{
        char_to_find,
        char_to_find,
        char_to_find,
        char_to_find,
        char_to_find,
        char_to_find,
        char_to_find,
        char_to_find};

    static const char *find(const char *begin, const char *end)
    {
        assert(begin <= end);
        if (begin == end) return end;

        for (const char *iter = begin; iter < end; iter += 8)
        {
            auto match = *reinterpret_cast<const size_t*>(iter) ^ *reinterpret_cast<const size_t*>(&mask.front());
            match = (match - 0x0101010101010101L) & ~match & 0x8080808080808080L;
            if (match)
            {
                return iter + (size_t)(std::countr_zero(match) >> 3);
            }
        }
        return end;
    }
};