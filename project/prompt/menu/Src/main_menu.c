#include "main_menu.h"

#define MAX_AERGS               20

//typedef int bool;
#define true                    1
#define false                   0

typedef enum{
  VAR_LONG = 32,
  VAR_SHORT = 16,
  VAR_CHAR = 8
} VAR_TYPE;


//#define NULL                    ((void *)0)


char cmd[128];
int cmd_size;


struct _CMD_TBL
{
  char *cmd;
  bool (*run)(struct _CMD_TBL *cptr, int argc, char **argv);
  char *usage;
  char *help;
  char *help_more;
};

#define CMD_TBL_TEST            {"test", do_test, 0, 0, 0}
#define CMD_TBL_XXX             {"xxx", do_xxx, 0, 0, 0}
#define CMD_TBL_END             {0, 0, 0, 0, 0}

void display_prompt(char *prompt);
bool do_print_help(int argc, char **argv);
int get_command(char *cmd, int len, int timeout);
int get_command_01(char *cmd, int len, int timeout);
int get_args(char *s, char **argv);
void main_menu(void);

bool do_test(struct _CMD_TBL *cptr, int argc, char **argv);
bool do_xxx(struct _CMD_TBL *cptr, int argc, char **argv);

struct _CMD_TBL cmd_tbl[] = {
  CMD_TBL_TEST,
  CMD_TBL_XXX,
  CMD_TBL_END
};


char get_byte(void)
{
    //while( !((*(volatile unsigned long *) 0x40013800) & 0x20) ) ;
    while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET) ;
    return (char) USART_ReceiveData(USART1);
    
}

int StrCmp(char *s1, char *s2){
  for(; *s1 && *s2; s1++, s2++){
    if(*s1 != *s2){
      return ((int)(*s1) - (int)(*s2));
    }
  }
  if(*s1 || *s2){
    return ((int)(*s1) - (int)(*s2));
  }
  return 0;
}

void main_menu(){
    /** ¿Œ¿⁄ ∞πºˆ */
    int argc = 0;
    /** ¿Œ¿⁄ ∞™ */
    char *argv[MAX_AERGS];
    /** µÓ∑œµ» ∏Ì∑…æÓ */
    struct _CMD_TBL *cptr = NULL;
    /** menu Ω««‡ */
    for(;;){
      
      display_prompt(">>> ");
      
      get_command_01(cmd, 128, 3600);
      /** not get command */
      if(!cmd || !cmd[0]){
        continue;
      }
      /** get argc */
      argc = get_args(cmd, argv);
      
      for(cptr = cmd_tbl; cptr->cmd; cptr++)
      {
        if(!StrCmp(argv[0], cptr->cmd)){
          if(cptr->run != 0){
            (cptr->run)(cptr, argc, argv);
            break;
          }
        }
      }
      /** help command */
      if(!StrCmp(argv[0], "help") || !StrCmp(argv[0], "?")){
        do_print_help(argc, argv);
      }else if(!(cptr->cmd)){
        printf("\tUnknown command : %s \r\n", argv[0]);
      }
      
      if(!StrCmp(argv[0], "end")){
          break;
      }
    }
}



void display_prompt(char *prompt)
{
    if (prompt == NULL)
    {
        printf(">>> ");
    }
    else
    {
        printf("%s", prompt);
    }
}

int get_command(char *cmd, int len, int timeout){
  char c;
  int i, rd_cnt, rd_max;
  rd_max = len - 1;
  
  for(rd_cnt = 0, i = 0; rd_cnt < rd_max;){
    c = get_byte();
    if((c == '\r') || (c == '\n')){
      cmd[i++] = '\0';
      printf("\r\n");
      return rd_cnt;
    }else if(c == '\b'){
      if(i > 0){
        i--;
        rd_cnt--;
        printf("\b\b");
      }
    }else{
      cmd[i++] = c;
      rd_cnt++;
      printf("%c", c);
    }
  }
  
}

int get_command_01(char *cmd, int len, int timeout){
  char c;
  int i, rd_cnt, rd_max;
  rd_max = len - 1;
  
  for(rd_cnt = 0, i = 0; rd_cnt < rd_max;){
    c = get_byte();
    if((c == '\r') || (c == '\n')){
      cmd[i++] = '\0';
      printf("\r\n");
      return rd_cnt;
    }else if(c == '\b'){
      if(i > 0){
        i--;
        rd_cnt--;
        printf("\b\b");
      }
    }else if(c == '\0'){
      cmd[cmd_size] = '\0';
      printf("\r\n");
      return cmd_size;
    }else{
      cmd[i++] = c;
      rd_cnt++;
      printf("%c", c);
    }
  }
}

int get_args(char *s, char **argv){
  int args = 0;
  if(!s || *s == '\0'){
    return 0;
  }
  while(args < MAX_AERGS){
    while((*s == ' ') || (*s == '\t')){
      s++;
    }
    if(*s == '\0'){
      argv[args] = 0;
      return args;
    }
    argv[args++] = s;
    while(*s && (*s != ' ') && (*s != '\t')){
      s++;
    }
    if(*s == '\0'){
      argv[args] = 0;
      return args;
    }
    *s++ = '\0';
  }
  return args;
 }

bool do_test(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("This is test\n");
    //test_main(argc, argv);    
    return true;
}


bool do_xxx(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("This is xxx\n");
    //xxx_main(argc, argv);    
    return true;
}

bool do_print_help(int argc, char **argv){
  struct _CMD_TBL *cptr;
  
  if(argc == 1){
    printf("The following command are supported: \r\n");
    printf("Help : Help for commands.\r\n");
    
    for(cptr = cmd_tbl; cptr->cmd; cptr++){
      if(cptr->help_more){
        printf(cptr->help_more);
      }
    }
    printf("\r\n");
  }else{
    printf("\tUnknown command : %s \r\n", argv[0]);
  }
  return true;
}

  
