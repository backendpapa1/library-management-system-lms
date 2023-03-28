#include <iostream>
#include "Book.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Book book = *new Book();
    book.createBook();
    return 0;
}
