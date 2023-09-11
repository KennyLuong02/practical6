
#include <iostream>

#include "BigNumCalc.h"


std::list<int> BigNumCalc::buildBigNum(std::string strInput) {

    std::list<int> listNum;

    for(int i=0 ; i<strInput.size() ; i++) {
        listNum.push_back(int(strInput[i]-48)); //Because the ASCII characters for numer value are numeber + 48
    }

    return listNum;
}


//Like how we do binary addition, values that went out of bound 10 (from 0-9 is bound 10)
//will get carry over to the next node. It's a linked list so recursion can't be used :(

std::list<int> BigNumCalc::add(std::list<int> num1Input , std::list<int> num2Input) {   

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

std::list<int> BigNumCalc::addCarry(std::list<int> num1In , std::list<int> num2In , int carry , std::list<int> curentList) {

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

std::list<int> BigNumCalc::sub(std::list<int> num1Input, std::list<int> num2Input) {
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

std::list<int> BigNumCalc::subCarry(std::list<int> num1In , std::list<int> num2In , int carry , std::list<int> currentList) {
    std::list<int>::reverse_iterator reIt1 = num1In.rbegin();
    std::list<int>::reverse_iterator reIt2 = num2In.rbegin();

    int insertNum;

    int carryVal = carry;


    for(reIt1 ; reIt1 != num1In.rend() ; reIt1++) {
        
        if(*reIt1 - (*reIt2 + carryVal) < 0 ) {
            insertNum = (*reIt1 + 10) - (*reIt2 + carryVal);    //If the result is lesser than 0, add 10 to first
            currentList.push_front(insertNum);                  //number, change carry to -1(to bring it to next value)
                                                                //And continue as normal (like 0 - 9 = 1 -> because 1 is the difference between 0 and 9)
            carryVal = -1;
        } else {
            insertNum = *reIt1 - *reIt2 + carryVal;
            currentList.push_front(insertNum);

            carryVal = 0;
        }

        reIt2++;
        

    }



    return currentList;
}






std::list<int> BigNumCalc::mul(std::list<int> num1Input , std::list<int> num2Input) {
    std::list<int> product = this->buildBigNum("0");

    if(num1Input.size() == 1) {                     //Just add() inside a for loop, because we only do single
                                                    //Digit multiplication, just pick the single digit one and do a bunch of adds
        for(int i=0 ; i < *num1Input.begin() ; i++) {
            product = this->add(num2Input , product);
        }

    } else if(num2Input.size() == 1) {

        for(int i=0 ; i < *num2Input.begin() ; i++) {
           product = this->add(num1Input , product); 
        }

    } else {
        std::cout << "Out of bounds" << std::endl;
    }

    return product;
}