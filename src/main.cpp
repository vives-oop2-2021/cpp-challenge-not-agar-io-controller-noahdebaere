// Main Program to run the command terminal controller for not agar.io
#include <iostream>
#include "lib/controller.h"

using namespace std;

int main() {
    NotAgarIOController::Controller controller;
    controller.start();
    

    return 0;
}