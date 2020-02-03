/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include "money.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

/*
 *
 * Can't figure out a way to account to loss of floating point precision
 *
 */

// convert current currency values to a string
string Money::toString() {
    return "";
}

//sets class variables to 0
void Money::reset () {
    total = 0.0;
    hundreds = 0;
    tens = 0;
    fives = 0;
    ones = 0;
    quarters = 0;
    dimes = 0;
    nickels = 0;
    cents = 0;
    st.str("");
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;

    ss << /*"$" << left << setfill('0') << setw(4) << */amount;

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    //set class variables to 0
    reset();

    //user input
    cout << "Hundreds: "; cin >> hundreds;
    cout << "Tens: "; cin >> tens;
    cout << "Fives: "; cin >> fives;
    cout << "Ones: "; cin >> ones;
    cout << "Quarters: "; cin >> quarters;
    cout << "Dimes: "; cin >> dimes;
    cout << "Nickels: "; cin >> nickels;
    cout << "Pennies: "; cin >> cents;

    //conversion to float
    total += hundreds * 100.0;
    total += tens * 10.0;
    total += fives * 5.0;
    total += ones * 1.0;
    total += quarters * .25;
    total += dimes * .1;
    total += nickels * .05;
    total += cents * .01;

    //prepare output
    st << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, " << quarters << " quarters, "
       << dimes << " dimes, " << nickels << " nickels, " << cents << " pennies = $" << total << endl;

    return st.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    double input;

    //set class variables to 0
    reset();

    //get user input
    cout << "Amount: "; cin >> input;

    //conversion to change formant
    toChangeFormat(input);

    //prepare output
    st << "$" << input << " = " << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, "
       << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << cents << " pennies." << endl;

    return st.str();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    double input;
    int dollars, coins;

    //set class variables to 0
    reset();

    //user input
    cout << "Check amount: "; cin >> input;

    //seperate dollars and coins
    input *= 100.0;
    coins = fmod(input, 100.0);
    dollars = input / 100;

    //prepare output
    st << toCurrency(dollars) << " dollars and " << toCurrency(coins) << " cents." << endl;

    return st.str();
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    double transaction, changeGiven;

    //set class variables to 0
    reset();

    //user input
    cout << "Change received: "; cin >> total;
    cout << "Transaction total: "; cin >> transaction;

    //calculating change to be given back
    changeGiven = total - transaction;

    //check if change is not enough to pay transaction
    if (changeGiven < 0) {
        return "Not enough change.";
    } else {
        //conversion to change format
        toChangeFormat(changeGiven);

        //prepare output
        st << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, "
           << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << cents << " pennies." << endl;
    }

    return st.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    double transaction, changeGiven;

    //set class variables to 0
    reset();

    //user change input
    cout << "Hundreds: "; cin >> hundreds;
    cout << "Tens: "; cin >> tens;
    cout << "Fives: "; cin >> fives;
    cout << "Ones: "; cin >> ones;
    cout << "Quarters: "; cin >> quarters;
    cout << "Dimes: "; cin >> dimes;
    cout << "Nickels: "; cin >> nickels;
    cout << "Pennies: "; cin >> cents;

    //conversion
    total += hundreds * 100.0;
    total += tens * 10.0;
    total += fives * 5.0;
    total += ones * 1.0;
    total += quarters * .25;
    total += dimes * .1;
    total += nickels * .05;
    total += cents * .01;

    //user transaction input
    cout << endl << "How much was the transaction: "; cin >> transaction;

    //calculating change to be given back
    changeGiven = total - transaction;

    //check if change is not enough to pay transaction
    if (changeGiven < 0) {
        return "Not enough change.";
    } else {
        //conversion to change format
        toChangeFormat (changeGiven);

        st << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, "<< quarters << " quarters, "
           << dimes << " dimes, " << nickels << " nickels, " << cents << " pennies." << endl;
    }

    return st.str();
}

//convert to change format
void Money::toChangeFormat (double change) {
    hundreds = change / 100;
    change -= hundreds * 100.0;

    tens = change / 10;
    change -= tens * 10.0;

    fives = change / 5;
    change -= fives * 5.0;

    ones = change / 1;
    change -= ones * 1.0;

    quarters = change / 0.25;
    change -= quarters * 0.25;

    dimes = change / 0.10;
    change -= dimes * 0.10;

    nickels = change / 0.05;
    change -= nickels * 0.05;

    cents = change / 0.01;
    change -= cents * 0.01;
}
