/*
Program File Name: Ch4Ex15
Programmer: Josh Richards
Date: October 25, 2024
Requirements:

Write a program that asks for the weight of the package and the distance it is to be shipped, then displays the charges.

Weight of Package (in Kilograms)            Rate per 500 Miles Shipped

    2 kg or less                            $1.10
    Over 2 kg but not more than 6 kg        $2.20
    Over 6 kg but not more than 10 kg       $3.70
    Over 10 kg but not more than 20 kg      $4.80

Input validation: Do not accept values of 0 or less for the weight of the package.
Do not accept weights of more than 20 kg (this is the maximum weight the company will ship).
Do not accept distance of less than 10 miles or more than 3,000 miles. 
These are the company's minimum and maximum shipping distances. 

*/

#include <iostream>
#include <cmath>
using namespace std;

double getRate(double weight) {
    if (weight <= 2) {
        return 1.10;
    }
    else if (weight <= 6) {
        return 2.20;
    }
    else if (weight <= 10) {
        return 3.70;
    }
    else {
        return 4.80;
    }
}

double calculateCharges(double rate, double distance) {
    int distanceBlocks = ceil(distance / 500.0);
    return rate * distanceBlocks;
}

bool isValidWeight(double weight) {
    return weight > 0 && weight <= 20;
}

bool isValidDistance(double distance) {
    return distance >= 10 && distance <= 3000;
}

int main()
{
    double weight, distance;

    cout << "Enter the weight of the package (in kg): ";
    cin >> weight;

    if (!isValidWeight(weight)) {
        cout << "Invalid weight. The weight must be more than 0 and no more than 20 kg." << endl;
        return 1;
    }

    cout << "Enter the distance to be shipped (in miles): ";
    cin >> distance;

    if (!isValidDistance(distance)) {
        cout << "Invalid distance. The distance must be between 10 and 3000 miles." << endl;
        return 1;
    }
    double rate = getRate(weight);
    double charges = calculateCharges(rate, distance);

    cout << "The shipping charge is: $" << charges << endl;

    return 0;
}

