//
// Created by backendpapa on 3/28/23.
//



//
// Created by backendpapa on 3/28/23.
//

#include <iostream>
#include <nlohmann/json.hpp>
#include "Book.h"


class Books {

    nlohmann::json ex1 = nlohmann::json::parse(R"(
        {
            "pi": 3.141,
            "happy": true
        }
    )");




    char bno[10]; // book number

public:
    void createBook(){
        std::cout << "\nNEW BOOK ENTRY" << std::endl;
        std::cout << "\nENTER BOOK NUMBER" << std::endl;
        std::cout << ex1["pi"];
        std::cin >> bno;

    }
};



