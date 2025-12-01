#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/stack.hpp"

TEST_CASE( "You can add 1 item to the Stack." ) {
    Stack<int> stack;
    REQUIRE( stack.size() == 0 );
    stack.push(10);
    REQUIRE( stack.size() == 1 );
    REQUIRE( stack.peek() == 10 );
}

TEST_CASE( "You can pop 1 item off the Stack." ) {
    Stack<int> stack;
    REQUIRE( stack.size() == 0 );
    stack.push(10);
    REQUIRE( stack.size() == 1 );
    REQUIRE( stack.pop() == 10 );
    REQUIRE( stack.size() == 0 );
}

TEST_CASE( "You can add many items to the Stack." ) {
    Stack<int> stack;
    REQUIRE( stack.size() == 0 );

    stack.push(10);
    REQUIRE( stack.size() == 1 );
    REQUIRE( stack.peek() == 10 );

    stack.push(5);
    REQUIRE( stack.size() == 2 );
    REQUIRE( stack.peek() == 5 );

    stack.push(7);
    REQUIRE( stack.size() == 3 );
    REQUIRE( stack.peek() == 7 );

    stack.push(23);
    REQUIRE( stack.size() == 4 );
    REQUIRE( stack.peek() == 23 );

    stack.push(14);
    REQUIRE( stack.size() == 5 );
    REQUIRE( stack.peek() == 14 );
}

TEST_CASE( "If you try to push an item when the stack is full, it will throw an exception" ) {
    Stack<int> stack;
    stack.push(10);
    stack.push(5);
    stack.push(7);
    stack.push(23);
    stack.push(14);

    REQUIRE_THROWS_AS( stack.push(2), std::out_of_range );
}

TEST_CASE( "You can pop many items off the stack" ) {
    Stack<int> stack;
    stack.push(10);
    stack.push(5);
    stack.push(7);
    stack.push(23);
    stack.push(14);

    REQUIRE( stack.pop() == 14 );
    REQUIRE( stack.pop() == 23 );
    REQUIRE( stack.pop() == 7 );
    REQUIRE( stack.pop() == 5 );
    REQUIRE( stack.pop() == 10 );
}

TEST_CASE( "If you try to pop something off the stack while it is empty, it will throw an exception" ) {
    Stack<int> stack;
    REQUIRE_THROWS_AS( stack.pop(), std::out_of_range );
}

TEST_CASE( "If you try to peek at the stack while it is empty, it will throw an exception" ) {
    Stack<int> stack;
    REQUIRE_THROWS_AS( stack.peek(), std::out_of_range );
}