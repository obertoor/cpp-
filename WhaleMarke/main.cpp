#include "interface.h"
#include "hint.h"

int main() {
    pullUsers();
    pullGoods();
    pullOrders();

    welcomeMessage();
    MAIN_Interface();
    exitingMessage();

    pushUsers();
    pushGoods();
    pushOrders();
    return 0;
}