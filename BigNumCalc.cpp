
#include <iostream>

#include "BigNumCalc.h"


std::list<int> bigNumCalc::buildBigNum(std::string strInput) {

    std::list<int> listNum;

    for(int i=0 ; i<strInput.size() ; i++) {
        listNum.push_back(int(strInput[i]-48)); //Because the ASCII characters for numer value are numeber + 48
    }

    return listNum;
}


//Like how we do binary addition, values that went out of bound 10 (from 0-9 is bound 10)
//will get carry over to the next node. It's a linked list so recursion can't be used :(

std::list<int> bigNumCalc::add(std::list<int> num1Input , std::list<int> num2Input) {   

    std::list<int> listReturn;

    if(num1Input.size() == num2Input.size()) {

        std::list<int>::iterator listPtr = num1Input.end();

        return addCarry(num1Input , num2Input , 0 , listReturn);

    } else if(num1Input.size() < num2Input.size()) {

        for(int i=0 ; i<(num2Input.size() - num1Input.size()) ; i++) {
            num1Input.push_front(0);
        }

    } else if(num1Input.size() > num2Input.size()) {

        for(int i=0 ; i<(num1Input.size() - num2Input.size()) ; i++) {
            num2Input.push_front(0);
        }

    }

    return addCarry(num1Input , num2Input , 0 , listReturn);

}   

std::list<int> bigNumCalc::addCarry(std::list<int> num1In , std::list<int> num2In , int carry , std::list<int> curentList) {

    std::list<int>::reverse_iterator riter1 = num1In.rbegin();

    std::list<int>::reverse_iterator riter2 = num2In.rbegin();

    int addNum; //Number to insert to the result

    int carryNum = carry;   //Value that gets carried to the next calculation

    for(riter1 ; riter1 != num1In.rend() ; riter1++) {
        addNum = (*riter1 + *riter2);
        
        curentList.push_front(addNum + carryNum);

        carryNum = ((*riter1 + *riter2) / 10) % 10;


        riter2++;
    }

    if(*curentList.begin() < 10) {

        return curentList;

    } else {
        int temp = *curentList.begin();
        curentList.pop_front();
        
        curentList.push_front(temp % 10);
        curentList.push_front(temp / 10);

        return curentList;
        
    }




}

std::list<int> bigNumCalc::sub(std::list<int> num1Input, std::list<int> num2Input) {
    std::list<int> listReturn;

    if (num1Input.size() == num2Input.size()) {
        std::list<int>::iterator listPtr = num1Input.end();

        return subCarry(num1Input, num2Input, 0, listReturn);
    } else if (num1Input.size() < num2Input.size()) {
        for (int i = 0; i < (num2Input.size() - num1Input.size()); i++) {
            num1Input.push_front(0);
        }
    } else if (num1Input.size() > num2Input.size()) {
        for (int i = 0; i < (num1Input.size() - num2Input.size()); i++) {
            num2Input.push_front(0);
        }
    }

    return subCarry(num1Input, num2Input, 0, listReturn);
}

std::list<int> bigNumCalc::mul(std::list<int> num1Input , std::list<int> num2Input) {
    std::list<int> product;
    int digit;
    
    int carry = 0;

    for (int x : num1Input) {
        int result = x * digit + carry;
        carry = result / 10;
        product.push_back(result % 10);
    }

    if (carry > 0) {
        product.push_back(carry);
    }

    return product;
}