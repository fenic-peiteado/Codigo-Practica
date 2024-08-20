#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vi;


class UnionFind {

  UnionFind(int sizeUnion) {
    ft.resize(sizeUnion);
    for(int i = 0 ; i< sizeUnion; i++) {
      ft[i] = i;
    }
  } 





  private:
  vi ft; // Buscar otro nombre mejor :)
};


int main() {
  int testCintase;
  std::cin >> testCase;
  int numberOfConsult;
  std::cin >> numberOfConsult;
  for(int i =  0; i < numberOfConsult; i++) {
    std::string typeConsult,link, toLinked;
    std::cin >> typeConsult >> link;


  }

  return 0;
}