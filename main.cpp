#include <iostream>
#include <cassert>

#include "src/dish.hpp"
#include "src/stack.hpp"

int main() {
    Stack<Dish> stack;

    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    assert( stack.size() == 0 );

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    assert( stack.size() == 4 );

    std::cout << stack.peek().get_description() << std::endl;
    std::cout << stack.pop().get_description() << std::endl;
    std::cout << stack.pop().get_description() << std::endl;

    assert( stack.size() == 2 );

    return 0;
}
