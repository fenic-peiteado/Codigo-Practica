#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

typedef std::vector<long> vi;

int main() {
  int firstValue, secondValue;
  while(std::cin >> firstValue >> secondValue){

  std::unordered_map<int, vi> values;
  long valueDirection;
  for (long positionInVector = 0; positionInVector < firstValue; positionInVector++) {
    std::cin >> valueDirection;
    values[valueDirection].push_back(positionInVector + 1); 
  }
  long ocurrency, value;
  while (secondValue--) {
    std::cin >> ocurrency >> value;
    if (values[value].size() >= ocurrency) {
      std::cout << values[value][ocurrency - 1] << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }
  }
}