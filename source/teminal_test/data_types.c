//Dont define stdio here we will include this library under stdio & stdlib & time under main source code.
typedef struct{
  char * text;
  long int timestamp;
  char * username;
}message;
typedef struct list{
  message msg;
  struct list * next;
}message_list;
typedef struct{
  char * username;
  message_list database;
}server;

  
