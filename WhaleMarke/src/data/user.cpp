#include "user.h"
#include"config.h"
#include "info.h"

#include <stdio.h>
#include <string.h>

static User users[MAX_USER]; // ���е��û�
static int totalUser = 0; // �û�����

/**
 * @brief ���ⲿ�ļ������û���Ϣ
 *
 */
static FILE* pf = NULL;
//static const char* filePath = "src/data/user.txt";
void pullUsers() {
    totalUser = 0; // ǰ���Ѿ�����
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
 * @brief ���û���Ϣ�������ⲿ�ļ�
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
 * @brief ��ȡ�û�����
 *
 * @param idex �û��ڵ������±�
 * @return User* ָ���Ӧ�û���ָ��
 */
User* getUser(int idex) { return users + idex; }

/**
 * @brief ��ӡ��ϸ���û���Ϣ
 *
 * @param i �û��������±�
 */
void userInfo(int i) {
    printf("ID:        | %s\n", users[i].id);
    printf("Name:      | %s\n", users[i].name);
    printf("Contact:   | %s\n", users[i].contact);
    printf("Address:   | %s\n", users[i].address);
    printf("Balance:   | %.1f\n", users[i].balance);
}

/**
 * @brief ������û�
 *
 * @param u ����ӵ��û�ָ��
 * @return ��ӳɹ�����1�����ʧ�ܷ���0
 */
static int searchUserName(const char* name) {//����֮ǰҪ��ֹ����
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
 * @brief ɾ������ID���û�
 *
 * @param id ��ɾ���û���id
 * @param who ɾ������ִ���ߵ�id������ԱΪnull
 * @return int ɾ���ɹ�����1��ʧ�ܷ���0
 */
static int searchUserID(const char* id) {
    for (int i = 0; i < totalUser; i++)
        if (strcmp(users[i].id, id) == 0) return i;
    return -1;
}

int deleteUser(const char* id, const char* who) {//who��ŵ�����Ϊ�����ID��ֻ�й���Ա��Ȩ��ɾ���û�������ԱIDΪNULL��
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
 * @brief ��ӡ�����û�����Ϣ
 *
 */
static const char* header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+";

/**
 * @brief ��ӡ�����û���Ϊ����һ��
 *
 * @param i �û��±�
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
 * @brief ����û����������Ƿ�ƥ��
 *
 * @param name �û���
 * @param passwd ����
 * @param idx ����ɹ���ͨ��ָ�뷵���û����±�
 * @return int ƥ��ɹ�����1��ʧ�ܷ���0
 */
int checkPass(const char* name, const char* passwd, int* idx) {
    *idx = searchUserName(name);
    if (*idx == -1) return 0;
    return strcmp(users[*idx].passwd, passwd) == 0;
}

/**
 * @brief �û���ֵ
 *
 * @param id ����ֵ�û�id
 * @param m ��ֵ����
 * @return ��ֵ�ɹ�����1��ʧ�ܷ���0
 */
int userTopUp(const char* id, double m) {
    int idx = searchUserID(id);
    if (idx == -1) return 0;
    users[idx].balance += m;
    return 1;
}