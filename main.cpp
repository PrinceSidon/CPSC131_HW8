#include <iostream>
#include <stdint.h>
#include <vector>

struct hashMap {
  // Hash table implemented as an int vector
  std::vector<int> hashTable;

  // Returns the bucket that hash will be stored in using linear probing
  int compression(uint64_t hash) {
    int size = hashTable.size();
    int collisions = 0;

    // The key is calculated by calculating hash % size
    int key = hash % size;

    /*
    If that key already has a value, a collision will keep being 
    added to the key, until a key without a value is found
    */
    while (hashTable[key] != NULL) {
      collisions++;
      key = (hash + collisions) % size;
    }

    // Sets the value at key to hash, and returns the key
    hashTable[key] = hash;
    return key;
  }
};

int main() {
  hashMap test;
  test.hashTable.resize(11);
  
  // Ten inputs that won't have collisions
  std::cout << "Ten inputs that won't have collisions:\n"<< std::endl;
  for (int i = 1; i < 11; i++) {
    std::cout << "Compression(" << i << "): " << test.compression(i) << std::endl;
  }

  std::cout << "\nHash table: ";
  for (int i = 0; i < test.hashTable.size(); i++) {
    std::cout << test.hashTable[i] << ", ";
  }

  // One input that will have collisions
  std::cout << "\n\n\nOne input that will have collisions:\n" << std::endl;
  std::cout << "Compression(12): " << test.compression(12) << std::endl;

  std::cout << "\nHash table: ";
  for (int i = 0; i < test.hashTable.size(); i++) {
    std::cout << test.hashTable[i] << ", ";
  }
}
