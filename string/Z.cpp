//created by Alexandra Gordey
#include <iostream>
#include <vector>
#include <string>

std::vector <int> z(std::string original_string) {
	std::vector <int> Z(original_string.length());
	int l, r = 0;
	Z[0] = original_string.length();
	for (int i = 1; i < original_string.length(); ++i) {
		if (i <= r) {
			Z[i] = std::min(Z[i - l], r - i + 1);
		} else {
			Z[i] = 0;
		}
		while (original_string[Z[i]] == original_string[i + Z[i]]) {
			++Z[i];	
		}
	if (Z[i]) {
		l = i;
		r = i + Z[i] - 1;
	}
	}
	return Z;
}



int main() {
    std::string substring, main_string;
    std::getline(std::cin, substring);
    std::getline(std::cin, main_string);
    std::string formated = substring + ">" + main_string;
    std::vector <int> Z_func = z(formated);
    for (int i = 0; i < Z_func.size(); ++i) {
        if (Z_func[i] == substring.length()) {
            std::cout << i - substring.length() - 1 << " ";
        }
    }
}
