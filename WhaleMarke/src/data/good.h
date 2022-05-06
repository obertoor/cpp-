#pragma once
#include "config.h"
typedef enum { SELLING, SOLD, BANNED } State;//��Ʒ������״̬�������С����۳������¼�
// ��Ʒ���Ͷ���
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
 * @brief ���ⲿ�ļ�������Ʒ��Ϣ
 *
 */
void pullGoods();

/**
 * @brief ����Ʒ��Ϣ�������ⲿ�ļ�
 *
 */
void pushGoods();

/**
 * @brief ��ȡ��Ʒ����
 *
 * @param idex ��Ʒ�ڵ������±�
 * @return User* ָ���Ӧ��Ʒ��ָ��
 */
Good* getGood(int idex);

/**
 * @brief �������Ʒ
 *
 * @param u ����ӵ���Ʒָ��
 * @return ��ӳɹ�����1�����ʧ�ܷ���0
 */
int addGood(Good* g);

/**
 * @brief ���Ҹ���ID����Ʒ
 *
 * @param id ��Ҫ���ҵ���ƷID
 * @return int �ɹ������±꣬ʧ�ܷ���-1
 */
int searchGoodID(const char* id);

/**
 * @brief ɾ������ID����Ʒ
 *
 * @param id ��ɾ����Ʒ��id
 * @param who ɾ������ִ���ߵ�id������ԱΪnull
 * @return int ɾ���ɹ�����1��ʧ�ܷ���0
 */
int deleteGood(const char* id, const char* who);

/**
 * @brief ��ӡ��ϸ����Ʒ��Ϣ
 *
 * @param i ��Ʒ�������±�
 */
void goodInfo(int i);

/**
 * @brief ��ӡ������Ʒ����Ϣ
 *
 */
void printGoods();

/**
 * @brief Ϊ���������Ʒ-ֻ�������ڳ����е���Ʒ
 *
 * @param name ��������Ʒ������
 */
void searchGoodName4Buyer(const char* name);

/**
 * @brief Ϊ����Ա������Ʒ-����������Ʒ
 * @param name ��������Ʒ������
 */
void searchGoodName4Admin(const char* name);

/**
 * @brief ��ӡ��������id����Ʒ
 *
 * @param id ��Ҫ��ӡ��Ʒ������id
 */
void printGoods4Seller(const char* id);

/**
 * @brief ��ӡ�����е���Ʒ
 *
 * @param id ��Ҫ��ӡ��Ʒ�����id
 */
void printGoods4Buyer(const char* id);