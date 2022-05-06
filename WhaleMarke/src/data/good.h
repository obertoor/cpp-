#pragma once
#include "config.h"
typedef enum { SELLING, SOLD, BANNED } State;//商品有三种状态：销售中、已售出、已下架
// 商品类型定义
typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char date[MAX_LEN];
    char description[MAX_LEN];
} Good;
// good.h

/**
 * @brief 从外部文件导入商品信息
 *
 */
void pullGoods();

/**
 * @brief 将商品信息导出到外部文件
 *
 */
void pushGoods();

/**
 * @brief 获取商品对象
 *
 * @param idex 商品在的数组下标
 * @return User* 指向对应商品的指针
 */
Good* getGood(int idex);

/**
 * @brief 添加新商品
 *
 * @param u 待添加的商品指针
 * @return 添加成功返回1，添加失败返回0
 */
int addGood(Good* g);

/**
 * @brief 查找给定ID的商品
 *
 * @param id 需要查找的商品ID
 * @return int 成功返回下标，失败返回-1
 */
int searchGoodID(const char* id);

/**
 * @brief 删除给定ID的商品
 *
 * @param id 待删除商品的id
 * @param who 删除操作执行者的id，管理员为null
 * @return int 删除成功返回1，失败返回0
 */
int deleteGood(const char* id, const char* who);

/**
 * @brief 打印详细的商品信息
 *
 * @param i 商品的数组下标
 */
void goodInfo(int i);

/**
 * @brief 打印所有商品的信息
 *
 */
void printGoods();

/**
 * @brief 为买家搜索商品-只搜索正在出售中的商品
 *
 * @param name 待搜索商品的名称
 */
void searchGoodName4Buyer(const char* name);

/**
 * @brief 为管理员搜索商品-搜索所有商品
 * @param name 待搜索商品的名称
 */
void searchGoodName4Admin(const char* name);

/**
 * @brief 打印给定卖家id的商品
 *
 * @param id 需要打印商品的卖家id
 */
void printGoods4Seller(const char* id);

/**
 * @brief 打印出售中的商品
 *
 * @param id 需要打印商品的买家id
 */
void printGoods4Buyer(const char* id);