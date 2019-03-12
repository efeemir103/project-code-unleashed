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
  sscanf(tmp,"%*c%*c%*c %*c%*c%*c %d %d:%d:%d %d",&res.day,&res.hour,&res.minute,&res.second,&res.year);
  sscanf(tmp,"%*c%*c%*c %c%c%c %*d %*d:%*d:%*d %*d",&tmpmonth[0],&tmpmonth[1],&tmpmonth[2]);
  tmpmonth[3]=0;
  if(!strcmp(tmpmonth,"Jan")){
    res.month=1;
  }elseif(!strcmp(tmpmonth,"Feb")){
    res.month=2;
  }elseif(!strcmp(tmpmonth,"Mar")){
    res.month=3;
  }elseif(!strcmp(tmpmonth,"Apr")){
    res.month=4;
  }elseif(!strcmp(tmpmonth,"May")){
    res.month=5;
  }elseif(!strcmp(tmpmonth,"Jun")){
    res.month=6;
  }elseif(!strcmp(tmpmonth,"Jul")){ 
    res.month=7;
  }elseif(!strcmp(tmpmonth,"Aug")){
    res.month=8;
  }elseif(!strcmp(tmpmonth,"Sep")){
    res.month=9;
  }elseif(!strcmp(tmpmonth,"Oct")){
    res.month=10;
  }elseif(!strcmp(tmpmonth,"Nov")){
    res.month=11;
  }elseif(!strcmp(tmpmonth,"Dec")){
    res.month=12;
  }else{
    printf("Error parsing month.");
  }
  return res;
