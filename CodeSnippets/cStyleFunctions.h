#include <cstdlib>
#include <cassert>

//默认dst有足够的空间去容纳src
char* strcpy(char* dst, const char* src) {//源指针所指的字符串内容是不能修改的，因此应该声明为 const 类
    assert (dst != NULL || src != NULL);

    char* tempDst = dst;
    while (*src != '\0') {
        *tempDst++ = *src++;
    }
    *tempDst = '\0';
    return dst;
}

size_t strlen(char* src) {
    assert (src != NULL);
    
    size_t count = 0;
    while (*src != '\0') {
        count++;
        src++;
    }
    return count;
}

//默认dst有足够的空间去容纳src
//如果dst和src有重叠怎么办？库函数实现默认调用者来处理，有重叠就别调用啊
char* strcat(char* dst, const char* src) {
    assert (dst != NULL || src != NULL);

    char* tempDst = dst;
    while (*tempDst != '\0')
        tempDst++;
    while (*src != '\0') {
        *tempDst++ = *src++;
    }
    *tempDst = '\0';
    return dst;
}


int strcmp(const char* dst, const char* src) {
    assert (dst != NULL || src != NULL);
    
    /*
    int ret = 0;
    while (*dst != '\0' && *src != '\0') {//因为必然是'\0'结尾，所以不需要考虑空指针的问题
        if (*dst > *src)
            return 1;
        else if (*dst < *src)
            return -1;
    }
    if (*dst == '\0' && *src == '\0')
        return 0;
    else if (*dst == '\0')
        return -1;
    else return 1;
    */
    while (*dst == *src) {
        if (*dst == '\0')
            return 0;
        ++dst;
        ++src;
    }
    return *dst - *src;
}

void* memcpy(void *dst, const void *src, size_t count) { 
//void指针要转成char指针，因为char指针才能++
//安全检查 
    assert( (dst != NULL) && (src != NULL) ); 
    unsigned char *pdst = (unsigned char *)dst; 
    const unsigned char *psrc = (const unsigned char *)src; 
//防止内存重复 
    assert(!(psrc <= pdst && pdst < psrc + count)); 
    assert(!(pdst <= psrc && psrc < pdst + count)); 
    while(count--) {
        *pdst = *psrc; 
        pdst++; 
        psrc++; 
    } 
    return dst; 
}

void* memmove(void *dst, const void *src, size_t count) {  
//void指针要转成char指针，因为char指针才能++
//安全检查 
    assert( (dst != NULL) && (src != NULL) ); 
    char *pdst = (char*)dst; 
    const char *psrc = (const char *)src;
    char *tmp;  
    const char *s;  

    //比较指针，确定高低位，针对性处理
    if (pdst <= psrc) {
        tmp = pdst;  
        s = psrc;  
        while (count--)  
            *tmp++ = *s++;  
    } else {  
        tmp = pdst;  
        tmp += count;  
        s = psrc;  
        s += count;  
        while (count--)  
            *--tmp = *--s;  
    }  
    return pdst;  
}  