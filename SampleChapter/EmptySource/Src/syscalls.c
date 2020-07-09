#include "hw_config.h"
#include "stm32f10x.h"
#include <stdlib.h>
#include "errno.h"
#include <sys/stat.h>
#include <sys/types.h>


__attribute__((used))
int _getpid(void){
    return 1;
}

/** printf */
__attribute__((used))
int _write(int fd, char *ptr, int len){
    size_t i;
    for(i = 0; i < len; i++){
        USART_SendData(USART1, ptr[i]);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
    return len;
}

/** scanf */
/*
__attribute__((used))
int _read(int fd, char *ptr, int len){
    size_t i;
    unsigned char data;
    for(; len > 0; len--){
        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
        data = USART_ReceiveData(USART1);
        if(data == '\n'){
            break;
        }
        *ptr++ = data;
        ++i;
    }

    return len;
}
*/
/** scanf */
/*
__attribute__((used))
size_t __read(int handle, unsigned char * buffer, size_t size)
{
    size_t nChars = 0;
    unsigned char c;
    if (handle != 0) return -1;
    for (; size > 0; --size)
    {
        while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == RESET);
        c = USART_ReceiveData(USART1);

        if (c == 0) break;

        *buffer++ = c;
        ++nChars;
    }
    return nChars;
}

__attribute__((used))
int _close(int file){
    return -1;
}
*/

__attribute__((used))
int _close(int file){
    return -1;
}