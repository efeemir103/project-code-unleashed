//Dont define stdio here we will include this library under stdio & stdlib & string & time under main source code.
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
typedef struct{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
}t_;
t_ get_time(time_t timestamp){
  char * tmp=ctime(&timestamp);
  char tmpmonth[4];
  t_ res;
  sscanf(tmp,"%*c%*c%*c %*c%*c%*c %d %d:%d:%d %d",&day,&hour,&minute,&second,&year);
  sscanf(tmp,"%*c%*c%*c %c%c%c %*d %*d:%*d:%*d %*d",&tmpmonth[0],&tmpmonth[1],&tmpmonth[2]);
  if(!strcmp(tmpmonth,"")//write months here
