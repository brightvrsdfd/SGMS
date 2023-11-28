# SGMS
Student Grade Management System, the Course Project of SCUT OS 2023

### Setup

1.Clone this repo from Github (SSH)
```
git clone git@github.com:brightvrsdfd/SGMS.git
```

2.Make file
```
cd SGMS
make
```

3.run server
```
./bin/server 8888
```

4.run client in another terminal
```
./bin/client 127.0.0.1 8888
```
### SGMS Structure

```
.:
    bin    (execution file) 
    client (client implementation)
    server (server implementation)
    Makefile
    README.md

./bin:
    client
    server

./client:
    client.c
    client.h
    client.o
    menu.c
    menu.o

./server:
    file.c 
    file.o 
    server.c 
    server.h 
    server.o  
    snapshot.c  
    snapshot.o  
    user.c  
    user.o
```

### 11/28
* Finished the overall structure of the SGMS