#pragma once
// menu.h
// 菜单类型
typedef enum { MAIN, ADMIN, USER, BUYER, SELLER, INFO, MODIFY, GOOD } Menu;
/**
 * @brief 菜单的作用是给出提示信息并获取用户输入
 *
 * @param type 菜单类型
 * @return int 用户的有效输入
 */
int menu(Menu type);
extern const int optionNum[];
