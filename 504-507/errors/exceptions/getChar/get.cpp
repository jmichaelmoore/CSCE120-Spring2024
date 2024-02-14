#include <iostream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string word = "supercalifragilisticexpialidocious"; // constructor initialzies to empty string, we'll see this soon
    size_t index = 0;
    do {
        cout << "Enter index to show letter or 9999 to exit: ";
        cin >> index;
        try {
            cout << word.at(index) << " is the letter at index " << index << endl;
        }
        catch (std::out_of_range &e) {
            cout << e.what() << endl;
        }
        catch (std::exception &e) {
            cout << e.what() << endl;
        }
        catch ( ... ) {
            cout << "unknown exception" << endl;
        }
    } while (index != 9999);
}