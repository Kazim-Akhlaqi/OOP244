/*
--------------------
Student Full_Name: Kazim Akhlaqi
Student_ID: 103638177
Stdent Email: kakhlaqi@myseneca.ca
Section: OOP244-SAB
Assignment: Workshop 1 - in_lab - tools.h
-------------------
*/
#ifndef SICT_TOOLS_H
#define SICT_TOOLS_H

#pragma once


namespace sict{

// Displays the user interface menu
int menu();

// Performs a fool-proof integer entry
int getInt(int min, int max);
}
#endif
