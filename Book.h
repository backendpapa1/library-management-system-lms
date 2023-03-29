//
// Created by backendpapa on 3/28/23.
//
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <fstream>


#ifndef LMS_BOOK_H
#define LMS_BOOK_H


using namespace std;

int on_exit(void (*function)(int, void *), void *arg);

class Book {
    nlohmann::json bookRepo;



public:
    char bno[6]; // book number
    char bname[100]; // book name
    Book(int totals){


//        atexit(closeClass(bookRepo));


        std::ofstream file("db.json");
        try {
            std::ifstream f("../db.json");
            setlocaldb(f);



        } catch (const exception& exc2) {
            cout << "Initializing Database" << endl;
            initializedb();
        };


    }

    ~Book()
    {
        storedata();
        cout << "closing";

    }
    void createBook(){
        std::cout << "\nNEW BOOK ENTRY" << std::endl;
        std::cout << "\nENTER BOOK NUMBER" << std::endl;
        std::cin >> bno;
        std::cout << "\nENTER BOOK NAME" << std::endl;
        std::cin >> bname;
        addBook(bno,bname);
    }

    void showBook(){
       try{
           char bcode[6];
           cout << "\n ENTER BOOK NUMBER";
           cin >> bcode;

           cout << "checking through db..." << endl;
           cout << bcode << endl;
           int bsize = (int) bookRepo.size();
           bool found = false;
           int value;
           for (int i = 0; i < bsize; i++) {
               if(bookRepo[i]["no"] == bcode){
                   value = i;
                   found = true;
                   break;
               }
           };
               if (!bookRepo[value].is_null() && found) {
                   cout << "book found! \n";
                   cout << bookRepo[value] << "\n";
               } else {
                   cout << "book not found! \n";
               }

       } catch (const exception& ex2) {
           cout << ex2.what() << endl;
           cout << "book not found! \n";
       }
    }


private:

    void addBook(char _bno[],char _bname[]){
        std::string bookNo;
        std::string bookName;
        bookNo.append(_bno);
        bookName.append(_bname);
        nlohmann::json ex1  = {
                {"no",bookNo},
                {"name", bookName},
        };
        std::cout << "book successfully added" << std::endl;
        addtodb(ex1);
        std::cout << bookRepo << bookNo << std::endl;


    }

    void initializedb(){
        nlohmann::json result = nlohmann::json::array();
        std::ofstream f("../db.json",std::ios_base::trunc |std::ios_base::out);
        f << result;
    }

    void setlocaldb(ifstream& f){
        nlohmann::json data = nlohmann::json::parse(f);
        bookRepo = data;
    }
    void addtodb(nlohmann::json& data){
        bookRepo.push_back(data);
    }

    void storedata(){
        std::ofstream closingData("../db.json",std::ios_base::trunc |std::ios_base::out);
        closingData << bookRepo;
    }



};






#endif //LMS_BOOK_H
