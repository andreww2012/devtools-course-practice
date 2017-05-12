// Copyright 2017 Kazakov Andrew

#ifndef MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_
#define MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

typedef std::vector<unsigned int> RegexSearchResult;

class RegexSearch {
 public:
    RegexSearch();
    explicit RegexSearch(const std::string);
    RegexSearch(const RegexSearch&);
    RegexSearch& operator=(const RegexSearch&);

    void SetRegex(const std::string);
    std::string GetRegex(void) const;

    RegexSearchResult Find(std::string str);
    RegexSearchResult FindInFile(std::string filename);

 protected:
    std::string regex_;
};

#endif
