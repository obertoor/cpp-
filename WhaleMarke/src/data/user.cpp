#include "user.h"
#include"config.h"
#include "info.h"

#include <stdio.h>
#include <string.h>

static User users[MAX_USER]; // 所有的用户
static int totalUser = 0; // 用户总数

/**
 * @brief 从外部文件导入用户信息
 *
 */
static FILE* pf = NULL;
//static const char* filePath = "src/data/user.txt";
void pullUsers() {
    totalUser = 0; // 前面已经定义
    //FILE* pf = fopen(filePath, "r");
    fopen_s(&pf, "D:\\CPP\\project\\WhaleMarke\\WhaleMarke\\src\\data\\user.txt", "r+");
    if (pf) {
        while (fscanf(pf, "%s%s%s%s%s%lf", users[totalUser].id, \
            users[totalUser].name, users[totalUser].passwd, users[totalUser].contact, \
            users[totalUser].address, &(users[totalUser].balance)) != EOF) totalUser++;
        fclose(pf);
    }
}

/**
 * @brief 将用户信息导出到外部文件
 *
 */
void pushUsers() {
    //FILE* pf = fopen(filePath, "w");
    fopen_s(&pf, "D:\\CPP\\project\\WhaleMarke\\WhaleMarke\\src\\data\\user.txt", "w+");
    for (int i = 0; i < totalUser; i++)
        fprintf(pf, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name, users[i].passwd, \
            users[i].contact, users[i].address, users[i].balance);
    fclose(pf);
}

/**
 * @brief 获取用户对象
 *
 * @param idex 用户在的数组下标
 * @return User* 指向对应用户的指针
 */
User* getUser(int idex) { return users + idex; }

/**
 * @brief 打印详细的用户信息
 *
 * @param i 用户的数组下标
 */
void userInfo(int i) {
    printf("ID:        | %s\n", users[i].id);
    printf("Name:      | %s\n", users[i].name);
    printf("Contact:   | %s\n", users[i].contact);
    printf("Address:   | %s\n", users[i].address);
    printf("Balance:   | %.1f\n", users[i].balance);
}

/**
 * @brief 添加新用户
 *
 * @param u 待添加的用户指针
 * @return 添加成功返回1，添加失败返回0
 */
static int searchUserName(const char* name) {//查找之前要防止重名
    for (int i = 0; i < totalUser; i++)
        if (strcmp(users[i].name, name) == 0) return i;
    return -1;
}
int addUser(User* u) {
    if (totalUser == MAX_USER) return 0;
    if (searchUserName(u->name) != -1) return 0;
    genID(u->id, 'U');
    users[totalUser++] = *u;
    return 1;
}

/**
 * @brief 删除给定ID的用户
 *
 * @param id 待删除用户的id
 * @param who 删除操作执行者的id，管理员为null
 * @return int 删除成功返回1，失败返回0
 */
static int searchUserID(const char* id) {
    for (int i = 0; i < totalUser; i++)
        if (strcmp(users[i].id, id) == 0) return i;
    return -1;
}

int deleteUser(const char* id, const char* who) {//who存放的是行为主体的ID，只有管理员有权限删除用户（管理员ID为NULL）
    if (who) return 0;
    int idx = searchUserID(id);
    if (idx == -1) return 0;
    for (int j = idx; j < totalUser - 1; j++) {
        users[j] = users[j + 1];
    }
    totalUser--;
    return 1;
}

/**
 * @brief 打印所有用户的信息
 *
 */
static const char* header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+";

/**
 * @brief 打印单个用户作为表格的一行
 *
 * @param i 用户下标
 */
static void printUser(int i) {
    printf("|%-10s |%-10s |%-10s |%-10s |%-10.1f |\n", users[i].id, users[i].name, \
        users[i].contact, users[i].address, users[i].balance);
}
void printUsers() {
    print_header
        for (int i = 0; i < totalUser; i++) {
            printUser(i);
            print_divide
        }
}

/**
 * @brief 检查用户名和密码是否匹配
 *
 * @param name 用户名
 * @param passwd 密码
 * @param idx 如果成功，通过指针返回用户的下标
 * @return int 匹配成功返回1，失败返回0
 */
int checkPass(const char* name, const char* passwd, int* idx) {
    *idx = searchUserName(name);
    if (*idx == -1) return 0;
    return strcmp(users[*idx].passwd, passwd) == 0;
}

/**
 * @brief 用户充值
 *
 * @param id 待充值用户id
 * @param m 充值数额
 * @return 充值成功返回1，失败返回0
 */
int userTopUp(const char* id, double m) {
    int idx = searchUserID(id);
    if (idx == -1) return 0;
    users[idx].balance += m;
    return 1;
}