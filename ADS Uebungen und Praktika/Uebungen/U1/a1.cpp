// includes
#include <iostream>
#include <list>
#include <stdexcept>
#include <stack>
#include <string>
#include <ctype.h>
#include <sstream>
#include "NodeE.h"
#include "NodeD.h"
#include "ListE.h"
#include "ListD.h"

#include "a1.h"

using namespace std;

// Teste Sie hier Ihre Methode Swap für eine einfach VL:
void ListETest(){
    ListE* l = new ListE();
    l->add(1);
    l->add(2);
    l->add(3);
    //l->add(4);
    //l->add(5);
    
    cout << "swap 0" << endl;
    l->swap(0);
    
    cout << "swap 1" << endl;
    l->swap(1);
    
    cout << "swap 2" << endl;
    l->swap(2);
    cout << l << endl;
}

// Teste Sie hier Ihre Methode Swap für eine doppelt VL:
void ListDTest(){
    ListD* l = new ListD();
    l->add(1);
    l->add(2);
    l->add(3);
    l->add(4);
    //l->add(5);
    
    cout << "swap 0" << endl;
    l->swap(0);
    
    cout << "swap 1" << endl;
    l->swap(1);
    
    cout << "swap 2" << endl;
    l->swap(2);
    cout << l << endl;
}

int a1(){
    ListETest();
    ListDTest();

    return 0;
}


