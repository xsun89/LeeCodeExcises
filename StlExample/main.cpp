#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    const std::string s = "102:330:3133:76531:451:000:12:44412";

    // Replace each colon with a single space
    const std::regex pattern(":");
    const std::string r = std::regex_replace(s, pattern, " ");

    std::istringstream ist(r);

    std::vector<int> numbers;
    std::copy(std::istream_iterator<int>(ist), std::istream_iterator<int>(),
              std::back_inserter(numbers));

    // We now have a vector of numbers

    // Print it out
    for (auto n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
    return 0;
}