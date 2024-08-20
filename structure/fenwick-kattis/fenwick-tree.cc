#include <iostream>
#include <vector>
#include <string>

#define LSOne(S) ((S) & -(S))

class FenwickTree {
 public:
  FenwickTree(long long sizeTree): sizeVector(sizeTree+1) {
    fc.assign(sizeTree + 1, 0);
  }

  inline long long ConsultOfValue(long long position) {
    if(position == 0) return 0;
    long long result = 0;
    for (; position; position -= LSOne(position)) {
      result += fc[position];
    }
    return result;
  }

  inline void Update(long long position, long long value) {
    for (; position < (long long)sizeVector; position += LSOne(position)) {
      fc[position] += value;
    }
  }

 private:
  std::vector<long long> fc;  // frequency acumulative
  long long sizeVector;
};

int main()  {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  long long sizeTree, numberOfConsultUpdate;
  std::cin >> sizeTree >> numberOfConsultUpdate;
  FenwickTree TreeConsult(sizeTree);
  char typeOfInput;
  long long position = 0, value = 0;
  for (long long i = 0; i < numberOfConsultUpdate; i++) {
    std::cin >> typeOfInput >> position;
    if (typeOfInput == '+') {
      std::cin >> value;
      // Puesto que el valor 0 no se utiliza, se le suma 1 a la posición
      TreeConsult.Update(position+1, value);
    }else {
      if (position == 0) {
        std::cout << 0 << "\n";
      } else {
      // No hace falta sumarle 1 a la posición porque es hasta el valor anterior
      // por tanto el valor en la posición es el mismo
        std::cout << TreeConsult.ConsultOfValue(position) << "\n";
      }
    }
  }
}