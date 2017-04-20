//
//  Attendant.cpp
//  Air Tycoon (Summative)
//
//  Created by - on 2017/04/18.
//  Copyright © 2017 Eddie of the House of Ren. All rights reserved.
//
#include <iostream>

#include "Attendant.hpp"
#include <sstream>
#include <string>

using namespace std;
string createInfoName();
string createAddress();
string createPhoneNumber();
void insertion_sort (string arr[], int arr2[], int length);


//Attendant::Attendant() {
//   
//    
//}
Attendant::Attendant() {
    //ticketSales = TicketSales;
    
    srand(static_cast<uint32_t>(time(0)));
    for (int x = 0; x < ROUTES_NUM; x++) {
        routes[x] = Flight(routeDestinations[rand()%10], x+1);
    } //Creates all the flights with a capacity of 10 passengers each
    
    for (int x = 0; x < PASSENGER_NUM; x++) {
        BasicInfo a;
        a.setName(createInfoName());
        a.setAddress(createAddress());
        a.setPhoneNumber(createPhoneNumber());
        cout << "Initializing customer "<<a.toString() ;
        customers[x] = Passenger(a, -1, routes[ROUTES_NUM], routeDestinations[rand()%5]);
    } //Creates all the passengers to be flown
    
}
string createInfoName() {
    stringstream a;
    string n1[10] = {"JOHN", "KATH", "MARK", "TOM", "TIM", "NICK", "FRANK", "LIAM", "GEORGE", "JUSTIN"};
    string n2[10] = {"ATHEN", "ALEEN", "ERSON", "Y", "" , "ALOS", "EN", "", "", "IAN"};
    string n3[10] = {"SMITH", "WEST", "CAPPER", "BROWN", "JAN", "ANTON", "WINK", "COOPER", "CHER", "BAIL"};
    a << n1[rand()%10] << n2[rand()%10] << " " << n3[rand()%10];
    return a.str();
}
string createAddress() {
    stringstream a;
    string n1[10] = {"Round", "Larson", "Main", "Fox", "Woods", "Shire", "Bagle", "Cather", "Forester", "Sevelt"};
    string n2[5] = {"Avenue", "Road", "Street", "Court", "Lane"};
    a << n1[rand()%10] << " " << n2[rand()%5];
    return a.str();
}
string createPhoneNumber() {
    stringstream a;
    a << "(" << rand()%100 + 800 << ") " << rand()%900+100 << "-" << rand()%9000 + 1000;
    return a.str();
}

int Attendant::getTicketSales() {
    return ticketSales;
}
Passenger& Attendant::getCustomers(int a) {
    return customers[a];
}
Flight& Attendant::getRoutes(int a) {
    return routes[a];
}
void Attendant::setTicketSales(int a) {
    ticketSales = a;
}
void Attendant::setCustomers(Passenger& a, int b) {
    customers[b] = a;
}
void Attendant::setRoutes(Flight& a, int b) {
    routes[b] = a;
}


void Attendant::addTicketSale() {
    ticketSales++;
}
void Attendant::cancelTicketSale() {
    ticketSales--;
}
string Attendant::displayRoutes() {
    stringstream a;
    
    return a.str();
}

void Attendant::reserveSeat(Passenger& a, Flight& b, int c) {
    
    for (int x = 0; x < SEAT_NUM; x++) {
        if (b.getFlightSeat(x).getSeatAvail() == true) {
            b.getFlightSeat(c).setSeatAvail(false);
            b.getFlightSeat(c).setSeatInfo(a.getMyInfo());
            a.setMyFlight(b);
        }
    }
}
void Attendant::cancelSeat(Passenger& a, Flight& b, int c) {
    int seatSerialNum = 0;
    BasicInfo basicInfo;
    b.getFlightSeat(c).setSeatAvail(true);
    b.getFlightSeat(c).setSeatInfo(basicInfo);
    a.setMySeatNum(-1);
    
    //Setting the passenger's seat number to -1 indicates he has nowhere to sit and thus will not board the plane
}

string Attendant::displayMyFlight(Flight a) {
    stringstream b;
    b << a.displayPassengerInfo() << endl << a.displaySeatsAvailible();
    return b.str();
}
string Attendant::displayNextCustomer() {
    stringstream a;
    for (int x = 0; x < PASSENGER_NUM; x++) {
        if (customers[x].getMySeatNum() == -1) {
            customers[x].toString();
            break;
        }
    }
    return a.str();
}
string Attendant::displayAllCustomerBySeatOrder(Flight a) {
    stringstream b;
    for (int x = 0; x < SEAT_NUM; x++) {
        b << a.getFlightSeat(x).toString() << endl;
    }
    return b.str();
}
string Attendant::displayAllCustomerByAlphabeticOrder(Flight a) {
    stringstream b;
    string passengerNames[10];
    int passengerNamesOrder[10];
    for (int x = 0; x < SEAT_NUM; x++) {
        passengerNames[x] = a.getFlightSeat(x).getSeatInfo().getName();
        passengerNamesOrder[x] = x;
    }
    insertion_sort(passengerNames,passengerNamesOrder, SEAT_NUM);
    for (int x = 0; x < SEAT_NUM; x++) {
        b << a.getFlightSeat(passengerNamesOrder[x]).toString() << endl;
    }
    return b.str();
} //Not fully tested yet, may not work

void Attendant::cancelFlight(Flight& a) {
    
}
void Attendant::reaccomodatePassengers(Flight& a)  {
    
}


void insertion_sort (string arr[], int arr2[], int length){
    int j;
    string temp;
    int temp2;
    for (int i = 0; i < length; i++){
        j = i;
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            temp2 = arr2[j];
            arr2[j] = arr2[j-1];
            arr2[j-1] = temp2;
            j--;
        }
    }
}



















