#include <iostream>
#include "HoleArray.h"

int main()
{
    std::cout << "Hello, World! HoleArray" << std::endl;
    HoleArray<int> ha;
    ha.append(10);
    std::cout << "After appending 10: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl;
    ha.append(20);
    std::cout << "After appending 20: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl;
    ha.append(30);
    std::cout << "After appending 30: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl;
    ha.insert(15, 1);
    std::cout << "After inserting 15 at index 1: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl;
    ha.remove(2);
    std::cout << "After removing item at index 2: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.insert(25, 2);
    std::cout << "After inserting 25 at index 2: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.insert(5, 0);
    std::cout << "After inserting 5 at index 0: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.insert(35, 5);
    std::cout << "After inserting 35 at index 5: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.remove(3);
    std::cout << "After removing item at index 3: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.remove(0);
    std::cout << "After removing item at index 0: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.remove(4);
    std::cout << "After removing item at index 4: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.insert(40, 2);
    std::cout << "After inserting 40 at index 2: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.insert(50, 5);
    std::cout << "After inserting 50 at index 5: " << ha.toString() << std::endl
              << "length: " << ha.getSize() << ", capacity: " << ha.getCapacity() << std::endl
              << "all holes size: " << ha.getAllHolesSize() << std::endl
              << "hole sum: " << ha.getHoleSum() << std::endl
              << "real size: " << ha.getRealSize() << std::endl
              << ha.printHoles() << std::endl;
    ha.get(2);
    std::cout << "Item at index 2: " << ha.get(2) << std::endl;

    ha.replace(2, 99);
    std::cout << "After replacing item at index 2 with 99: " << ha.toString() << std::endl;
    return 0;
}