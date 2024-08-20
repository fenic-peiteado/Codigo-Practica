#include <fstream>
#include <iostream>
#include <vector>

int main() {
  // Abandonado porque la solucion es más simple, y se puede calcula las posciones con simple calculo de suma de posiciones relativa con la posicon absoluta
  // y para detecta error solo deber comprobar que la suma de la posicon de relativa y absoluta no se pasan del numero de coches y no es un numero negativo.



  // mi calcula implicaba recorre el array y ir restando las posiciones a cada valor de esa manera se iba actualiznaod pero implicaba un solucion que podrias ser cuadratica
  // O(n^2)  y la otra solucion es lineal.
  // Read file
  int numberOfCase;
  std::cin >> numberOfCase;
  std::vector<std::pair<int, int>> arrayOfPositionValueRace;
  int checkValueRace = 0;  // 0 is Correct; else is incorrect
  int firstValueInput, secondValueInput;
  for (int i; i < numberOfCase; i++) {
    std::cin >> firstValueInput >> secondValueInput;
    arrayOfPositionValueRace.push_back(
        std::make_pair(firstValueInput, secondValueInput));
    checkValueRace += secondValueInput;
  }
  if (checkValueRace != 0) {
    std::cout << "-1";
  } else {
    for (int sizeArrayPosition = 0; sizeArrayPosition < arrayOfPositionValueRace.size(); sizeArrayPosition++) {
      int numberPositionToChange = abs(arrayOfPositionValueRace[sizeArrayPosition].second);
      for (int offsetNewPosition = 1; offsetNewPosition <= numberPositionToChange; offsetNewPosition++) {
        if(arrayOfPositionValueRace[sizeArrayPosition+offsetNewPosition].second > 0){
          arrayOfPositionValueRace[sizeArrayPosition+ offsetNewPosition].second -= 1;
        }else if (arrayOfPositionValueRace[sizeArrayPosition+offsetNewPosition].second < 0){
          arrayOfPositionValueRace[sizeArrayPosition+ offsetNewPosition].second += 1;
        }
      }
    
      // change position

    }
  }

  // Validadcion de dato en par en caso dede dar que la suma este incorrecta se
  // imprimer -1

  // Se debe recolocar las posicones y se determina por los valores del para
  // asignado
}