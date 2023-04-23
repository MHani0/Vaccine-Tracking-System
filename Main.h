#pragma once

#include <QtWidgets/QApplication>
#include <qdebug.h>
#include<iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "User.h"

#include <unordered_map>
#include "User.h"

//Main.cpp functions
void save_data(unordered_map<string, User>&, string);
void load_data(unordered_map<string, User>&, string);
