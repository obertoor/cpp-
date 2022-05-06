#include "good.h"
#include "info.h"
#include <stdio.h>
#include <string.h>
static Good goods[MAX_GOOD]; // all goods
static int totalGood = 0;

// good.h
/**
管理员可以查看全部的商品（包括已下架的）
买家只能查看正在销售中的商品
卖家只能查看自己出售的商品
/

/**
 * @brief 从外部文件导入商品信息
 *
 */
static FILE* pf = NULL;

//static const char* filePath = "src/data/good.txt";
void pullGoods() {
    totalGood = 0;
    //FILE* pf = fopen(filePath, "r");
    fopen_s(&pf, "D:\\CPP\\project\\WhaleMarke\\WhaleMarke\\src\\data\\good.txt", "r+");
    if (pf) {
        while (fscanf(pf, "%s%s%lf%s%u%s%s", goods[totalGood].id, \
            goods[totalGood].name, &goods[totalGood].price, goods[totalGood].seller_id, \
            & goods[totalGood].state, goods[totalGood].date, goods[totalGood].description) != EOF) totalGood++;
        fclose(pf);
    }
}

/**
 * @brief 将商品信息导出到外部文件
 *
 */
void pushGoods() {
    //FILE* pf = fopen(filePath, "w");
    fopen_s(&pf, "D:\\CPP\\project\\WhaleMarke\\WhaleMarke\\src\\data\\good.txt", "w+");
    for (int i = 0; i < totalGood; i++)
        fprintf(pf, "%s %s %.1f %s %u %s %s\n", goods[i].id, goods[i].name, goods[i].price, \
            goods[i].seller_id, goods[i].state, goods[i].date, goods[i].description);
    fclose(pf);
}

/**
 * @brief 获取商品对象
 *
 * @param idex 商品在的数组下标
 * @return User* 指向对应商品的指针
 */
Good* getGood(int idex) { return goods + idex; }

/**
 * @brief 添加新商品
 *
 * @param u 待添加的商品指针
 * @return 添加成功返回1，添加失败返回0
 */
int addGood(Good* g) {
    if (totalGood == MAX_GOOD) return 0;
    genID(g->id, 'G');
    getDate(g->date);
    g->state = SELLING;
    goods[totalGood++] = *g;
    return 1;
}

/**
 * @brief 查找给定ID的商品
 *
 * @param id 需要查找的商品ID
 * @return int 成功返回下标，失败返回-1
 */
int searchGoodID(const char* id) {
    for (int i = 0; i < totalGood; i++)
        if (strcmp(goods[i].id, id) == 0) return i;
    return -1;
}

/**
 * @brief 删除给定ID的商品
 *
 * @param id 待删除商品的id
 * @param who 删除操作执行者的id，管理员为null
 * @return int 删除成功返回1，失败返回0
 */
int deleteGood(const char* id, const char* who) {
    int idx = searchGoodID(id);
    if (idx == -1) return 0;
    if (who && strcmp(goods[idx].seller_id, who)) return 0;
    goods[idx].state = BANNED;
    return 1;
}

/**
 * @brief 打印详细的商品信息
 *
 * @param i 商品的数组下标
 */
static const char* stateName[] = { "Selling", "Sold", "Banned" };
void goodInfo(int i) {
    printf("ID:            | %s\n", goods[i].id);
    printf("Name:          | %s\n", goods[i].name);
    printf("Description:   | %s\n", goods[i].description);
    printf("Date:          | %s\n", goods[i].date);
    printf("Price:         | %.1f\n", goods[i].price);
    printf("Seller:        | %s\n", goods[i].seller_id);
    printf("State:         | %s\n", stateName[goods[i].state]);
}

/**
 * @brief 打印所有商品的信息
 *
 */
static const char* header = "|ID         |Name       |Price      |Date       |Seller     |State      |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";
/**
 * @brief 打印单个商品作为表格的一行
 *
 * @param i 用户下标
 */
static void printGood(int i) {
    printf("|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n", goods[i].id, goods[i].name, goods[i].price, \
        goods[i].date, goods[i].seller_id, stateName[goods[i].state]);
}
void printGoods() {
    print_header
        for (int i = 0; i < totalGood; i++) {
            printGood(i);
            print_divide
        }
}

/**
 * @brief 为买家搜索商品-只搜索正在出售中的商品
 *
 * @param name 待搜索商品的名称
 */
void searchGoodName4Buyer(const char* name) {
    print_header
        for (int i = 0; i < totalGood; i++)
            if (goods[i].state == SELLING && strstr(goods[i].name, name)) {
                printGood(i);
                print_divide
            }
}

/**
 * @brief 为管理员搜索商品-搜索所有商品
 * @param name 待搜索商品的名称
 */
void searchGoodName4Admin(const char* name) {
    print_header
        for (int i = 0; i < totalGood; i++)
            if (strstr(goods[i].name, name)) {
                printGood(i);
                print_divide
            }
}

/**
 * @brief 打印给定卖家id的商品
 *
 * @param id 需要打印商品的卖家id
 */
void printGoods4Seller(const char* id) {
    print_header
        for (int i = 0; i < totalGood; i++)
            if (strcmp(goods[i].seller_id, id) == 0) {
                printGood(i);
                print_divide
            }
}
/**
 * @brief 打印出售中的商品
 *
 * @param id 需要打印商品的买家id
 */
void searchGoodName4Admin(const char* name, const char* id) {
    print_header
        for (int i = 0; i < totalGood; i++)
            if (strstr(goods[i].name, name)) {
                printGood(i);
                print_divide
            }
}

void printGoods4Buyer(const char* id) {
    print_header
        for (int i = 0; i < totalGood; i++)
            if (goods[i].state == SELLING) {
                printGood(i);
                print_divide
            }
}