//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

int puzzle_sample_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_sample_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int puzzle_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int do_puzzle_1(std::ifstream &file) {
    PatternList pattern_list;
    Pattern pattern;

    std::string line;

    while (std::getline(file, line)) {
        // check if line is empty
        if (line.empty()) {
            pattern_list.emplace_back(pattern);
            pattern.clear();
            continue;
        }

        Row row;

        for (auto &c: line) {
            row.push_back(pattern_map.at(c));
        }

        pattern.push_back(row);
    }

    pattern_list.emplace_back(pattern);

    uint64_t sum = 0;
    for (auto &pattern: pattern_list) {
        sum += get_pattern_sum(pattern);
    }

    return sum;
}

uint64_t get_pattern_sum(const Pattern &pattern) {
    uint64_t sum = 0;

    // check horizontal reflection
    const Row &row1 = pattern[0];
    size_t row_reflection_point = 0;

    for (size_t i = 1; i < row1.size() ; ++i) {
        bool found_reflection_point = true;

        for (const auto &row: pattern) {
            found_reflection_point = is_row_reflection_point(row, i);

            if (!found_reflection_point) {
                break;
            }
        }

        if (found_reflection_point) {
            row_reflection_point = i;
            break;
        }
    }

    // check vertical reflection
    size_t col_reflection_point = 0;

    for (size_t i = 1; i < pattern.size(); ++i) {
        bool found_reflection_point = true;

        for (size_t j = 0; j < pattern[i].size(); ++j) {
            found_reflection_point = is_col_reflection_point(pattern, j, i);

            if (!found_reflection_point) {
                break;
            }
        }

        if (found_reflection_point) {
            col_reflection_point = i;
            break;
        }
    }

    return row_reflection_point + (col_reflection_point * 100);
}

bool is_row_reflection_point(const Row &row, size_t index) {
    size_t row_size = row.size();
    size_t len = std::min(index, row_size - index);

    for (size_t i = 0; i < len; ++i) {
        if (row[index - 1 - i] != row[index + i]) {
            return false;
        }
    }

    return true;
}

bool is_col_reflection_point(const Pattern &pattern, const size_t col_index, size_t index) {
    size_t col_size = pattern.size();
    size_t len = std::min(index, col_size - index);

    for (size_t i = 0; i < len; ++i) {
        if (pattern[index - 1 - i][col_index] != pattern[index + i][col_index]) {
            return false;
        }
    }

    return true;
}

int do_puzzle_2(std::ifstream &file) {
    std::string line;

    while (std::getline(file, line)) {
        fmt::println("{}", line);
    }

    return 0;
}
