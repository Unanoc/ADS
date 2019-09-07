#include <iostream>
#include <map>

int main() {
    std::map<char, int> romans;
    romans['I'] = 1;
    romans['V'] = 5;
    romans['X'] = 10;
    romans['L'] = 50;
    romans['C'] = 100;
    romans['D'] = 500;
    romans['M'] = 1000;

    std::string romanValue;
    std::cin >> romanValue;

    int summa = romans[romanValue[0]];

    for (int i = 1; i < romanValue.length(); i++) {
      if (romans[romanValue[i]] > romans[romanValue[i-1]])
        summa -= 2*romans[romanValue[i-1]];
      summa += romans[romanValue[i]];

    }

    std::cout << summa;

    return 0;
}
