//Dont define stdio here we will include this library under stdio & stdlib & string & time under main source code.
int message_size=sizeof(message);
typedef struct{
  char * text;
  time_t timestamp;
  char * username;
}message;

typedef struct list{
  message msg;
  struct list * next;
}message_list;

typedef struct{
  char * name;
  char * host_username;
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

t_ get_time(time_t timestamp){//returns time structure t_ builded from timestamp
  char * tmp=ctime(&timestamp);
  char tmpmonth[4];
  t_ res;
  sscanf(tmp,"%*c%*c%*c %*c%*c%*c %d %d:%d:%d %d",&res.day,&res.hour,&res.minute,&res.second,&res.year);
  sscanf(tmp,"%*c%*c%*c %c%c%c %*d %*d:%*d:%*d %*d",&tmpmonth[0],&tmpmonth[1],&tmpmonth[2]);
  tmpmonth[3]=0;
  if(!strcmp(tmpmonth,"Jan")){
    res.month=1;
  }else if(!strcmp(tmpmonth,"Feb")){
    res.month=2;
  }else if(!strcmp(tmpmonth,"Mar")){
    res.month=3;
  }else if(!strcmp(tmpmonth,"Apr")){
    res.month=4;
  }else if(!strcmp(tmpmonth,"May")){
    res.month=5;
  }else if(!strcmp(tmpmonth,"Jun")){
    res.month=6;
  }else if(!strcmp(tmpmonth,"Jul")){ 
    res.month=7;
  }else if(!strcmp(tmpmonth,"Aug")){
    res.month=8;
  }else if(!strcmp(tmpmonth,"Sep")){
    res.month=9;
  }else if(!strcmp(tmpmonth,"Oct")){
    res.month=10;
  }else if(!strcmp(tmpmonth,"Nov")){
    res.month=11;
  }else if(!strcmp(tmpmonth,"Dec")){
    res.month=12;
  }else{
    printf("Error parsing month.\n");
  }
  return res;
}

void append_message(message_list * database, message * newmessage){
  database->next=newmessage;
  database->next->next=NULL;
}
void delete_message(message_list * database, char * text){
  message_list * tmp=database;
  if(database==NULL){
    printf("There is no message in this database.");
  }else{
    while(1){
      if(tmp->next!=NULL){//if next element doesnt exist stop.
        if(strcmp(tmp->next.msg.text,text)){//if message found at next element stop.
          break;
        }else{//if not found yet iterate
          tmp=tmp->next;
        }
      }else{
        break;
      }
    }
    if(tmp==NULL){
      printf("Error while itering over messages. Message not found.\n");//print error if message not found.
    }else{
      if(temp->next->next==NULL){//delete if it is the last message
        free(temp->next);
        temp->next=NULL;
      }else{//delete message in between two messages
        message_list * temp=tmp->next;
        tmp->next=temp->next;
        free(temp);
      }
    }
  }
}
