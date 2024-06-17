//
// Created by diogo on 17/06/2024.
//
#include <gtest/gtest.h>
#include "Client.h"
#include <string>
#include "ClientList.h"

TEST(ClientTest, ClientNamePassWordConstructor) { // UC visitor 1 - Create Account
string username = "user";
string password = "pWord";
Client client(username, password);

EXPECT_TRUE(username == client.getUsername());
EXPECT_TRUE(password == client.getPassword());
EXPECT_TRUE(client.getName().empty());
}

TEST(ClientTest, ClientFullInfoConstructor){ //
string username = "user";
string password = "password";
string address = "adress";
string name = "name";
unsigned int nif = 123456789;
Client client(username, password, address,name, nif);

EXPECT_TRUE(username == client.getUsername());
EXPECT_TRUE(password == client.getPassword());
EXPECT_TRUE(address == client.getAddress());
EXPECT_TRUE(name == client.getName());
EXPECT_TRUE(nif == client.getNif());
}

TEST(ClientOrderTest, ClientOrderConstructor) {
Date date;
std::string username = "user";
std::string password = "pWord";
Client client(username, password);
float value = 10.0;

ClientOrder clientOrder(date, &client, value);

EXPECT_EQ(username, clientOrder.getClient()->getUsername());
EXPECT_EQ(password, clientOrder.getClient()->getPassword());
EXPECT_FLOAT_EQ(value, clientOrder.getValue());
}

TEST(CreateAccountTest, SameUserName){
string username1 = "username1";
string passWord1 = "passWord1";

string username2 = "username1";  //The same as the username1
string passWord2 = "passWord2";

Client client1 (username1, passWord1);
Client client2 (username2, passWord2);
ClientList clientList;
clientList.addClient(client1);
bool flag = false;
try{
clientList.addClient(client2);
}catch(DuplicateEntryException& e){
flag = true;
}
EXPECT_TRUE(flag);
}

TEST(CreateAccountTest, DifferentUserName){
string username1 = "username1";
string passWord1 = "passWord1";

string username2 = "username2";  //Different from the username1
string passWord2 = "passWord2";

Client client1 (username1, passWord1);
Client client2 (username2, passWord2);
ClientList clientList;
clientList.addClient(client1);
bool flag = false;
try{
clientList.addClient(client2);
}catch(DuplicateEntryException& e){
flag = true;
}
EXPECT_FALSE(flag);
}