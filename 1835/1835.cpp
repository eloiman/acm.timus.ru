#include <stdio.h>
#include <list>
#include <limits.h>

#ifndef ONLINE_JUDGE
#define TRACE(...)  fprintf(stderr, __VA_ARGS__)
#else
#define TRACE(...)  ;
#endif

#define INPUT_MAX_SIZE          (1000000UL)

using namespace std;


struct STextBlock {
    char *pbegin;
    char *pend;
    unsigned long sz;
    char *pat;
};

typedef list<STextBlock *>              lst_text_blocks;
typedef lst_text_blocks::iterator       ilst_text_blocks;

struct SState {
    char                *pinput;
    lst_text_blocks     email_blocks;
};

static SState s_state;

int parse_input()
{
    int ret_val = 0;
    STextBlock *tb = NULL;
    unsigned long i = 0;
    char *in = s_state.pinput;
    
    do {
        if (('\0' == *in || ' ' == *in)) {
            if (tb) {
                tb->pend = in;
                tb->sz = tb->pend - tb->pbegin;
                s_state.email_blocks.push_back(tb);
                tb = NULL;
            }
        } else {
            if (!tb) {
                tb = new STextBlock();                
                tb->pbegin = in;
            }
            if ('@' == *in) {
                tb->pat = in;
            }
        }
    } while(*in++);

    return ret_val;
}

int read_input()
{
    char *pinput = new char [INPUT_MAX_SIZE + 1];
    char *ploc = pinput;
    size_t res = 0;
    
    do {
        res = fread(ploc, INT_MAX, 1, stdin);
        ploc += res;
    } while(res);

    s_state.pinput = pinput;

    return 0;
}

void trace_blocks() 
{
    char *buff = NULL;
    ilst_text_blocks iter = s_state.email_blocks.begin();

    while (iter != s_state.email_blocks.end()) {
        buff = new char [(*iter)->sz + 1];
        strcpy(buff, (*iter)->pbegin);
        TRACE("%s\n", buff);
        delete [] buff;
        iter++;
    }
}

int main()
{
    TRACE("1835\n");

    read_input();
    parse_input();
    trace_blocks();
}
