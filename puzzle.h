//
// Created by Vlad Isan on 05/12/2023.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "fmt/core.h"

enum class PatternType {
    ASH,
    ROCK
};

const std::unordered_map<char, PatternType> pattern_map{
    {'.', PatternType::ASH},
    {'#', PatternType::ROCK}
};

const std::unordered_map<PatternType, char> pattern_map_reverse{
    {PatternType::ASH, '.'},
    {PatternType::ROCK, '#'}
};

using Row = std::vector<PatternType>;
using Pattern = std::vector<Row>;
using PatternList = std::vector<Pattern>;


uint64_t get_pattern_sum(const Pattern &pattern);
bool is_row_reflection_point(const Row &row, size_t index);
bool is_col_reflection_point(const Pattern &pattern, size_t col_index, size_t index);

int puzzle_sample_1(const std::string &base_file_path);

int puzzle_sample_2(const std::string &base_file_path);

int puzzle_1(const std::string &base_file_path);

int puzzle_2(const std::string &base_file_path);

int do_puzzle_1(std::ifstream &file);

int do_puzzle_2(std::ifstream &file);

#endif //PUZZLE_H
