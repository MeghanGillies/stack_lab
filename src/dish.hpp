#pragma once

#include <string>

class Dish {
  private:
    std::string description;

  public:
    // Needed to add default constructor. It caused an error without one.
    Dish() {
      this->description = "";
    }

    Dish(std::string description) {
      this->description = description;
    }

    std::string get_description() {
      return this->description;
    }
};