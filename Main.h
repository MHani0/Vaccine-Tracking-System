#pragma once

#include <QtWidgets/QApplication>
#include <qdebug.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include "User.h"
#include "LinkedList.h"
#include <queue>


//Global variables
inline string loggedInUserID; //the currently logged in user
inline string chosenUserID = ""; //admin chosen user
inline double malesRatio, femalesRatio, unvaccinatedRatio, firstdoseRatio, seconddoseRatio = 0.0;
//Main.cpp variables
inline unordered_map <string, User> userHash;
inline vector <string> hashKeysOrdered; //to maintain the order of insertion of hash table
inline queue <string> not_vaccinated;
inline LinkedList vaccinated;

//Main.cpp functions
void save_data(unordered_map<string, User>&, string);
void load_data(unordered_map<string, User>&, string);
void handlingDoses();
void deleteUser(string);
bool isDigitString(const string&);
string trim(const std::string& s);
void Advanced_statistics();


