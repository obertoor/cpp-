#pragma once
// menu.h
// �˵�����
typedef enum { MAIN, ADMIN, USER, BUYER, SELLER, INFO, MODIFY, GOOD } Menu;
/**
 * @brief �˵��������Ǹ�����ʾ��Ϣ����ȡ�û�����
 *
 * @param type �˵�����
 * @return int �û�����Ч����
 */
int menu(Menu type);
extern const int optionNum[];
