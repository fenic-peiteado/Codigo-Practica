#include <iostream>
#include <vector>
typedef std::vector<int> vi;

class UnionFind {
  
  public:
  UnionFind (int numberOfDirection, int numberOfLeaders) {
    direction.resize(numberOfDirection);
    setSize.resize(numberOfDirection);
    leaders.resize(numberOfLeaders);
    for(int i = 0; i < direction.size(); i++ ) {
      direction[i] = i;
      setSize[i] = 1;
    }
  }

  int FindSet(int i ) {
    if(direction[i] == i){
      return i;
    }else{
      // std::cout << "Update" << i << "\n";
      return direction[i] = FindSet(direction[i]);
    }
  }

  bool SameSet(int FirstValue, int SecondValue) {
    return FindSet(FirstValue) == FindSet(SecondValue);
  }

  void UnionSet(int firstDirection , int secondDirection ) {
    if (SameSet(firstDirection, secondDirection)) {
        return;
    } 
    //Establecemo que el tenga menor valor de p[i] se el conjunto determinante
    int firstPosibleFather = FindSet(firstDirection);
    int secondPosibleFather = FindSet(secondDirection);
    if (firstPosibleFather <= secondPosibleFather) {
      direction[secondPosibleFather] = firstPosibleFather;
      setSize[firstPosibleFather] += setSize[secondPosibleFather];
    }else{
      direction[firstPosibleFather]  = secondPosibleFather;
      setSize[secondPosibleFather] += setSize[firstPosibleFather];
    }
  }

  /**
   * @brief Update of value leader
   * @param leaderValue value that introudce
   * @param numberGroup the group that you want update
   */
  void DefineLeader(int leaderValue, int numberGroup) {
    leaders[numberGroup] = leaderValue;
  }

  /// @brief Obtain size of value i 
  /// @param  The value that you can consult
  /// @return size of group
  int GetSizeOf(int i) {
    return setSize[i];
  }
  /// @brief Obtain leader each of groups
  /// @return 
  std::vector<int> GetLeader(){
    return leaders;
  }

  // Getter of de direction
  std::vector<int> GetDirection() {
    return direction;
  } 

  private: 
  vi direction;
  vi setSize;
  vi leaders;
};


int main()  {
  int numberOfStudent,numberOfGroups;
  while(std::cin >> numberOfStudent >> numberOfGroups){
    if( numberOfGroups == 0 && numberOfStudent == 0){
      return 0;
    }
  UnionFind storeGroup(numberOfStudent, numberOfGroups);
  int auxValueInput,posValue;
  while(numberOfGroups--) {
    int numberOfRepetion;
    std::cin >> numberOfRepetion;
    std::cin >> auxValueInput;
    storeGroup.DefineLeader(auxValueInput, numberOfGroups);
    numberOfRepetion--;
    while(numberOfRepetion--) {
      std::cin >> posValue;
      storeGroup.UnionSet(auxValueInput, posValue);
      auxValueInput = auxValueInput;
    }
  }
  //Recorremos los lideres y observamos cuanto tiene el 0
  vi valuesToCheck = storeGroup.GetLeader();
  int contador = 0;
  for(auto i: valuesToCheck){
    // std::cout<< "lider " << i << "\n";
    // std::cout << storeGroup.FindSet(i) << "\n";
    if(storeGroup.FindSet(i) == 0) {
      contador++;
    }
  }
  //Actualizamos
  std::vector<int> updateAux = storeGroup.GetDirection();
  std::cout << storeGroup.GetSizeOf(0) << "\n";
  }
}