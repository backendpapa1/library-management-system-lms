//
// Created by backendpapa on 3/28/23.
//
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <fstream>

#ifndef LMS_BOOK_H
#define LMS_BOOK_H


class Book {

    nlohmann::json bookRepo;

public:
    Book(int totals){
        std::cout << totals << std::endl;
        std::ofstream file("db.json");
        std::ifstream f("db.json");

        try {
//            fix data returning
            nlohmann::json data = nlohmann::json::parse(f);
            bookRepo = data;
            std::cout << bookRepo.size() << std::endl;
        } catch (const nlohmann::json_abi_v3_11_2::detail::parse_error& exc2) {
            std::cout << "errored" << std::endl;
            std::cout << exc2.what() << std::endl;
            bookRepo = R"([])"_json;
            file << bookRepo;
        };


    }
    void createBook(){
        char bno[10]; // book number
        char bname[100]; // book name

        std::cout << "\nNEW BOOK ENTRY" << std::endl;
        std::cout << "\nENTER BOOK NUMBER" << std::endl;
        std::cin >> bno;
        std::cout << "\nENTER BOOK NAME" << std::endl;
        std::cin >> bname;
        bookStore(bno,bname);

    }


private:

    void bookStore(char _bno[],char _bname[]){
        std::string bookNo;
        std::string bookName;
        bookNo.append(_bno);
        bookName.append(_bname);
        nlohmann::json ex1  = {
                {"no",bookNo},
                {"name", bookName},
        };
        std::cout << "working" << bookNo << std::endl;


    }

    void initializedb(){

    }
};






#endif //LMS_BOOK_H
