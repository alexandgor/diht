//created by Alexandra Gordey

#include <iostream>
#include <vector>
#include <string>

std::vector <int> prefix_function(std::string whole_string) {
    int n = whole_string.length();
    std::vector <int> prefix(n);
    prefix[0] = 0;
    for (int i = 1; i < n; ++i) {
        int potential_prefix = prefix[i - 1];
        while (whole_string[i] != whole_string[potential_prefix] && potential_prefix != 0) {
            potential_prefix = prefix[potential_prefix - 1];
        }
        if (whole_string[i] == whole_string[potential_prefix]) {
            prefix[i] = potential_prefix + 1;
        } else {
            prefix[i] = 0;
        }
    }
    return prefix;
}

int main() {
    std::string substring, main_string;
    std::getline(std::cin, substring);
    int substr_length =  substring.length();
    std::getline(std::cin, main_string);
    std::string formated = substring + ">" + main_string;
    std::vector <int> prefix = prefix_function(formated);
    for (int i = 0; i < prefix.size(); ++i) {
        if (prefix[i] == substr_length) {
            std::cout << (i - 2*substr_length) << " ";
        }
    }
    return 0;
}
