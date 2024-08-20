#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

bool isThereTree(std::multimap<int, int> graph, int point,
                 std::set<int> &visited) {
  std::stack<int> nextPoint;
  bool isTree = false;
  nextPoint.push(point);
  while (nextPoint.size()) {
    int actualPoint = nextPoint.top();
    nextPoint.pop();
    auto posibleRange = graph.equal_range(actualPoint);
    for (auto it = posibleRange.first; it != posibleRange.second; it++) {
      if (visited.find(it->second) != visited.end()) {
      } else {
        nextPoint.push(it->second);
        isTree = true;
        visited.insert(it->second);
      }
    }
  }
  return isTree;
}

int main() {
  int test;
  std::cin >> test;
  while (test--) {
    std::vector<std::string> input;
    std::string lineString;
    while (std::cin >> lineString && lineString[0] != '*') {
      input.push_back(lineString);
    }
    // we read all point of the graph, like A,B...
    std::string pointOfGraph;
    std::cin >> pointOfGraph;
    std::stringstream inputPoints(pointOfGraph);
    std::set<char> pointsSet;
    while (std::getline(inputPoints, pointOfGraph, ',')) {
      pointsSet.insert(pointOfGraph[0]);
    }
    std::multimap<int, int> graph;
    for (auto i : input) {
      graph.insert(std::make_pair(i[1], i[3]));
      graph.insert(std::make_pair(i[3], i[1]));
    }

    // Hacemos un dfa para obtener el arbol asociado
    std::set<int> visited;
    int numberOfTree = 0;
    int numberOfAcorn = 0;
    for (auto pointInSet : pointsSet) {
      if (visited.find(pointInSet) == visited.end()) {
        if (isThereTree(graph, pointInSet, visited)) {
          numberOfTree++;
        } else {
          numberOfAcorn++;
        }
      }
    }
    std::cout << "There are " << numberOfTree << " tree(s) and "
              << numberOfAcorn << " acorn(s).\n";
  }
}