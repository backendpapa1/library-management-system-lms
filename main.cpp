#include <iostream>
#include "Book.h"
#include "Book.cpp"
// MAIN LOOP PROBLEMATIC
void loadMenu(){
    cout <<"\n\n\tADMINISTRATOR MENU";
    cout <<"\n\n\t1.BOOK RELATED ACTIVITES";
    cout <<"\n\n\t-1.EXIT";
};

void bookMenu(){
    cout <<"\n\n\tBOOK MENU";
    cout <<"\n\n\t11.ADD A NEW BOOK";
    cout <<"\n\n\t12.FIND A BOOK";
    cout <<"\n\n\t-1.EXIT";
}

int main() {
    Book book(10);


    while(true){
        loadMenu();
        int key;
        cin >> key;
        if(key == 1){
            bookMenu();
            cin >> key;
            if(key == 11){
                book.createBook();
            }
            if(key == 12 ){
                book.showBook();
            }
            key = 0;
        }

        if(key == -1){
            cout << "ending application";
            break;
        }

    }
    return 0;
}
