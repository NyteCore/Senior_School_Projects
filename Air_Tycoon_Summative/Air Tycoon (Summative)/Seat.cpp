//
//  Seat.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/12.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Seat.hpp"
#include <string>
#include <sstream>

using namespace std;

Seat::Seat() {}
Seat::Seat(int SeatNumber, bool SeatAvail) {
    seatNumber = SeatNumber;
    seatAvail = SeatAvail;
}
Seat::Seat(int SeatNumber, bool SeatAvail, BasicInfo& a) {
    seatNumber = SeatNumber;
    seatAvail = SeatAvail;
    seatInfo = a;
    
}
int Seat::getSeatNumber() {
    return seatNumber;
}
bool Seat::getSeatAvail() {
    return seatAvail;
}
BasicInfo& Seat::getSeatInfo() {
    return seatInfo;
}
void Seat::setSeatNumber(int a) {
    seatNumber = a;
}
void Seat::setSeatAvail(bool a) {
    seatAvail = a;
}
void Seat::setSeatInfo(BasicInfo& a) {
    seatInfo = a;
}
string Seat::toString() {
    int spacing = 10;
    stringstream b;
    string sAvail;
    if (seatAvail == true) {
        sAvail = "Yes";
    } else {
        sAvail = "No";
    }
    b <<  "Passenger Name: " << seatInfo.getName() << setw(spacing)  << ", Contact: " << seatInfo.getPhoneNumber() << setw(spacing) << ", Address: " << seatInfo.getAddress() << setw(spacing) << ", Seat No." << seatNumber << setw(spacing) << ", Availiblility: " << sAvail ;
    
    return b.str();
}
