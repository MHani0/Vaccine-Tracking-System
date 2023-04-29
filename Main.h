#pragma once

#include <QtWidgets/QApplication>
#include <qdebug.h>
#include<iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "User.h"
#include "LinkedList.h"
#include <queue>



//Main.cpp variables
inline unordered_map <string, User> userHash;
inline LinkedList vaccinated_list;


//Main.cpp functions
void save_data(unordered_map<string, User>&, string);
void load_data(unordered_map<string, User>&, string);
void handlingDoses();
void Basic_statistics();
void delUser(string);

inline queue <string> not_vaccinated;
inline LinkedList vaccinated;
