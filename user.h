#ifndef USER_H
#define USER_H

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// 用户类型
typedef enum {
    ADMIN,
    TEACHER,
    STUDENT
} UserType;

// 用户信息结构体
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    UserType type;
    // 其他可能的用户信息
} User;

// 用户类型的字符串表示
extern const char* UserTypeStrings[];

// 用户管理函数
User* createUser(const char* username, const char* password, UserType type);
void deleteUser(User* user);
void modifyUser(User* user, const char* newPassword);
void printUserInfo(User* user);

// 用户身份验证函数
int authenticateUser(User* user, const char* enteredPassword);

#endif // USER_H
