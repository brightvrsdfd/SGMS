# Student Grade Management System
Course Design of OS, SCUT, 2023


## Members

| Team Member | Responsibilities                       |
|-------------|----------------------------------------|
| Zhiyu Jiang (江知雨)   | File System Management, User Management|
| Haoquan Zhang (张皓泉) | Course Management, Server-Client Communication |
| Zhizhan Zhang (张治展) | Grade Management, Integration Testing  |
| Xupeng Gu (古旭鹏)     | Assignment Management, Permissions Handling |

## 11/19
初步实现一些简单的 `server` 端函数实现


## 一个客户端向服务端发送请求的示例

当服务器端收到来自客户端的请求时，它应该能够根据请求的类型和用户的身份（管理员、教师、学生）来调用适当的函数。以下是一个示例流程，以老师登录并修改学生成绩、发布作业为例：

### 1. 老师登录过程：

* 服务器接收来自客户端的登录请求。
* 服务器调用身份验证函数，验证用户名和密码，并确定用户的身份为教师。
* 如果验证成功，服务器返回教师的用户类型。

### 2. 老师修改学生成绩过程：

* 服务器接收来自客户端的修改学生成绩请求。
* 服务器检查用户的身份，如果是教师，则继续处理。
* 服务器调用相应的函数，例如 `modifyStudentGrade`，并传递学生姓名和新的成绩。
* 函数在成绩管理模块中查找学生，修改相应的成绩。

### 3. 老师发布作业过程：

* 服务器接收来自客户端的发布作业请求。
* 服务器检查用户的身份，如果是教师，则继续处理。
* 服务器调用相应的函数，例如 `publishAssignment`，并传递作业名称和内容。
* 函数在作业管理模块中创建新的作业，设置作业的名称和内容。

整个过程的关键是在服务器端组织代码以处理不同类型的请求和用户身份。服务器端应该具有模块化的设计，允许容易扩展和维护。例如，可以有单独的模块处理用户管理、成绩管理、作业管理等功能。
