#pragma once
// user.h

#include "config.h"

// �û������Ͷ���
typedef struct {
    char id[MAX_LEN];//
    char name[MAX_LEN];
    char passwd[MAX_LEN];
    char contact[MAX_LEN];//��ϵ��ʽ
    char address[MAX_LEN];//סַ
    double balance;//���
} User;
/**
 * @brief ���ⲿ�ļ������û���Ϣ
 *
 */
void pullUsers();

/**
 * @brief ���û���Ϣ�������ⲿ�ļ�
 *
 */
void pushUsers();

/**
 * @brief ��ȡ�û�����
 *
 * @param idex �û��ڵ������±�
 * @return User* ָ���Ӧ�û���ָ��
 */
User* getUser(int idex);

/**
 * @brief ��ӡ��ϸ���û���Ϣ
 *
 * @param i �û��������±�
 */
void userInfo(int i);

/**
 * @brief ������û�
 *
 * @param u ����ӵ��û�ָ��
 * @return ��ӳɹ�����1�����ʧ�ܷ���0
 */
int addUser(User* u);

/**
 * @brief ɾ������ID���û�
 *
 * @param id ��ɾ���û���id
 * @param who ɾ������ִ���ߵ�id������ԱΪnull
 * @return int ɾ���ɹ�����1��ʧ�ܷ���0
 */
int deleteUser(const char* id, const char* who);

/**
 * @brief ��ӡ�����û�����Ϣ
 *
 */
void printUsers();

/**
 * @brief ����û����������Ƿ�ƥ��
 *
 * @param name �û���
 * @param passwd ����
 * @param idx ����ɹ���ͨ��ָ�뷵���û����±�
 * @return int ƥ��ɹ�����1��ʧ�ܷ���0
 */
int checkPass(const char* name, const char* passwd, int* idx);

/**
 * @brief �û���ֵ
 *
 * @param id ����ֵ�û�id
 * @param m ��ֵ����
 * @return ��ֵ�ɹ�����1��ʧ�ܷ���0
 */
int userTopUp(const char* id, double m);