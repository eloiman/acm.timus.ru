#include <stdio.h>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <err.h>
#include <vector>
#include <ctype.h>

#ifndef ONLINE_JUDGE
#define TRACE(...)  fprintf(stderr, __VA_ARGS__)
#else
#define TRACE(...)  ;
#endif

using namespace std;


struct STextBlock {
    int ninput_begin;
    char *pbegin;
    int ninput_end;
    char *pend;
    unsigned long sz;
    char *pat;
};

typedef list<STextBlock *>              text_blocks;
typedef text_blocks::iterator           text_blocks_iter;

struct SInputBlock {
    char *pinput;
    unsigned long sz;
};

typedef vector<SInputBlock *>           input_blocks;
typedef input_blocks::iterator          input_blocks_iter;

struct SState {
    input_blocks    input;
    text_blocks     email_blks;
};

static SState s_state;

int parse_input()
{
    unsigned long ninput = 0;
    unsigned long len = 0;
    int ret_val = 0;
    STextBlock *tb = NULL;
    unsigned long i = 0;
    char *in = NULL;
    char ch;
    input_blocks_iter input_iter = s_state.input.begin();
    
    while (input_iter != s_state.input.end()) {
        len = 0;
        in = (*input_iter)->pinput;
        do {
            if (('\0' == *in || ' ' == *in)) {
                ch = *in;
                if (tb) {
                    tb->ninput_end = ninput;
                    tb->pend = in;
                    if (tb->ninput_begin == tb->ninput_end) {
                        tb->sz = tb->pend - tb->pbegin;
                    } else {
                        tb->sz = 0; 
                    }
                    s_state.email_blks.push_back(tb);
                    tb = NULL;
                    *in = '\0';
                }
                if ('\0' == ch) {
                    break;
                }
            } else if ('.' == *in || '@' == *in || islower(*in)) {
                if (!tb) {
                    tb = new STextBlock();                
                    tb->ninput_begin = ninput;
                    tb->pbegin = in;
                }
                if ('@' == *in) {
                    tb->pat = in;
                }
            }
            len++;
            in++;
        } while(len < (*input_iter)->sz);
        ninput++;
        input_iter++;
    }

    return ret_val;
}

int read_input()
{
    char *pinput = (char *) malloc(INT_MAX);
    size_t res = 0;
    SInputBlock *input_block = NULL;

    do {
        res = fread(pinput, INT_MAX - 1, 1, stdin);
        if (!ferror(stdin)) {
            pinput[INT_MAX - 1] = '\0';
            input_block = new SInputBlock();
            input_block->pinput = pinput;
            input_block->sz = INT_MAX - 1;
            s_state.input.push_back(input_block);
            if (!feof(stdin)) {
                pinput = (char *) malloc(INT_MAX);
            }
        }
    } while(!ferror(stdin) && !feof(stdin));

    //TRACE("feof : %d; ferror %d; errno = %d (%s)\n", feof(stdin), ferror(stdin), errno, strerror(errno));

    return 0;
}

void trace_blocks() 
{
    unsigned long nsegi;
    unsigned long i = 0;
    char *ploc = NULL;    
    text_blocks_iter iter = s_state.email_blks.begin();

    while (iter != s_state.email_blks.end()) {
        TRACE("%lu : ", i);
        nsegi = (*iter)->ninput_begin;
        ploc = (*iter)->pbegin;
        while(nsegi <= (*iter)->ninput_end) {
            TRACE("%s", ploc);
            ploc = s_state.input[nsegi]->pinput;
            nsegi++;
        }
        TRACE("\n");
        iter++;
        i++;
    }
}

int main()
{
    TRACE("1835\n");

    read_input();
    parse_input();
    trace_blocks();
}
