#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include "GraphComponents.h"
#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

#define N 1000

using namespace std;


// Πρωτότυπο της συνάρτησης για το parsing
void parseCommand(char *command, Graph &graph);


// Συνάρτηση που αποστέλλει την εντολή προς εκτέλεση
void SendCommand(char *buffer, Graph &graph);

