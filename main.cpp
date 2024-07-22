#include <iostream>
#include <map>
#include <string>

bool isSurname(const std::string& surname) {
    if (surname.empty()) {
        return false;
    }
    if (std::all_of(surname.begin(),
                    surname.end(),
                    [](char c) { return !std::isalpha(c); })) {
        return false;
    }
    return true;
}

void sort(std::map<int, std::string>& list) {
    int count = static_cast<int>(list.size());
    for (int i = 0; i <= count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::string k = list[j];
                list[j] = list[j + 1];
                list[j + 1] = k;
            }
        }
    }
}


int main() {
    std::map<int, std::string> list;
    int count = 0;
    int next = 0;
    while (true) {
        std::string input;
        std::cout << "Enter a surname (or 'exit' to quit): ";
        std::cin >> input;
        if (input == "exit") {
            break;
        } else if (input == "next") {
            std::cout << "Next: " << list[next] << std::endl;
            ++next;
        } else if (isSurname(input)) {
            list[count] = input;
            ++count;
            sort(list);
        }
    }
    return 0;
}
