// goodInterface.c
//修改商品信息交互界面框架
#include "interface.h"


#include <stdio.h>
#include <string.h>

int curGood = -1;

make_modify(name, G, ood)
make_modify(description, G, ood)

static void modify_price() {
    char buffer[MAX_LEN];
    printf("Please input new price: ");
    scanf("%s", buffer);
    check_double
    Good* x = getGood(curGood);
    x->price = m;
    successMessage();
}

static HANDLER handler[] = { modify_name, modify_price, modify_description };
make_interface(G, OOD)
