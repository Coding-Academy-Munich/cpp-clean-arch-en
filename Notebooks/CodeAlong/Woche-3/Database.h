#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std::string_literals;

std::vector<std::string> GenerateRandomVector() {
    // Create a vector with the names of 20 famous computer scientists.
    std::vector<std::string> words{
        "Dijkstra"s, "Knuth"s,    "Turing"s,  "Hopper"s,      "Lovelace"s,
        "Babbage"s,  "Hamilton"s, "Boole"s,   "Berners-Lee"s, "Atanasoff"s,
        "Allen"s,    "Cerf"s,     "Kay"s,     "Engelbart"s,   "Stepanov"s,
        "McCarthy"s, "Torvalds"s, "Ritchie"s, "Stroustrup"s,  "Sutter"};
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<std::size_t> num_elements_dist{3, 6};
    std::uniform_int_distribution<std::size_t> word_choice_dist{0, words.size() - 1};

    std::vector<std::string> result;
    auto num{num_elements_dist(gen)};
    for (std::size_t i{0}; i < num; ++i) {
        result.push_back(words[word_choice_dist(gen)]);
    }
    return result;
}

class Database {
public:
    std::vector<std::string> Execute(std::string sql) {
        std::cout << "Executing SQL: " << sql << std::endl;
        return GenerateRandomVector();
    }

    std::vector<std::string> Execute(std::string sql, std::string data) {
        std::cout << "Executing SQL: " << sql << " with data " << data << std::endl;
        return GenerateRandomVector();
    }
};

#endif // DATABASE_H