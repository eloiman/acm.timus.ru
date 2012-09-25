#include <stdio.h>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <err.h>
#include <vector>
#include <map>
#include <utility>
#include <ctype.h>

#ifndef ONLINE_JUDGE
#define TRACE(...)  fprintf(stderr, __VA_ARGS__)
#else
#define TRACE(...)  ;
#endif

#define ALLOC_SIZE	        (32767)
#define NLETTERS            (('z' - 'a' + 1) + 1)
#define LETTER_IDX(L)       (('.' == L) ? 0 : (L - 'a' + 1))
#define MAKE_LPATH(L)       (LETTER_IDX(L) << NLETTERS)
#define SET_LPATH(L, P)     (P = P | LETTER_IDX(L))
#define TEST_LPATH(P, L)    (P = P & ~(1 << LETTER_IDX(L)))
#define SET_LPATH_IDX(LI, P)     (P = P | LI)
#define TEST_LPATH_IDX(P, LI)    (P = P & ~(1 << LI))

using namespace std;

struct SInputBlock {
    char *pinput;
    unsigned long sz;
};

typedef vector<SInputBlock *>           input_blocks;
typedef input_blocks::iterator          input_blocks_iter;

typedef unsigned char                   letter;
typedef unsigned long                   epos;
typedef unsigned long                   lpath;

typedef lpath *                         arr_lpath;
typedef map<epos, arr_lpath>            map_pos_letters;
typedef pair<epos, arr_lpath>           pair_pos_letters;
typedef lpath *                         arr_ats;

struct SState {
    input_blocks        input;
    map_pos_letters     emails_user_graph;
    map_pos_letters     emails_domain_graph;
    arr_ats             emails_at_graph;
};

static SState s_state;

typedef enum {
    ISUSER,
    ISAT,
    ISDOMAIN
} ISUAD;

int add_letter(ISUAD uad, epos pos, letter prev_letter, letter new_letter) 
{
    int ret_val = 0;
    lpath prev_lpath = 0;
    arr_lpath parr_lpath = NULL;
    unsigned char prev_letter_idx = LETTER_IDX(prev_letter);
    unsigned char letter_idx = LETTER_IDX(new_letter);

    if (ISUSER == uad) {
        map_pos_letters::iterator impl = s_state.emails_user_graph.find(pos);
        if (impl == s_state.emails_user_graph.end()) {
            parr_lpath = new lpath[NLETTERS];
            fill(parr_lpath, parr_lpath + NLETTERS, 0);
            s_state.emails_user_graph[pos] = parr_lpath;
        } else {
            parr_lpath = (*impl).second;
        }
        SET_LPATH_IDX(parr_lpath[prev_letter_idx], letter_idx);
    } else if (ISUSER == uad) {
        map_pos_letters::iterator impl = s_state.emails_domain_graph.find(pos);
        if (impl == s_state.emails_domain_graph.end()) {
            parr_lpath = new lpath[NLETTERS];
            fill(parr_lpath, parr_lpath + NLETTERS, 0);
            s_state.emails_user_graph[pos] = parr_lpath;
        } else {
            parr_lpath = (*impl).second;
        }
        SET_LPATH_IDX(parr_lpath[prev_letter_idx], letter_idx);
    } else if (ISAT == uad) {
        SET_LPATH_IDX(s_state.emails_at_graph[prev_letter_idx], letter_idx);
    } else {
        exit(0);
    }
    
    return 0;
}


void parse_input()
{
    enum {
        USER,
        DOMAIN,
        USER_DOMAIN
    } udstatus = USER;
    enum {
        PREV_NONE,
        PREV_AT,
        PREV_LETTER,
        PREV_DOR
    } prevstatus = PREV_NONE;
    unsigned long inpos = 0;
    char *in = NULL;
    char ch = '\0';
    char prevch = '\0';
    unsigned char seg = 0;
    input_blocks_iter input_iter;
    unsigned char *puser = NULL;
    unsigned char user_seg = 0;
    unsigned char *pdomain = NULL;
    unsigned char domain_seg = 0;
    unsigned long char_pos = 0;
        
    seg = 0;
    input_iter = s_state.input.begin();
    while (input_iter != s_state.input.end()) {
        inpos = 0;
        in = (*input_iter)->pinput;
        do {
            ch = in;
            if ('.' == ch) {
                if (PREV_LETTER != prevstatus) {
                    puser = in;
                    user_seg = seg;
                }
            }
            prevch = ch;
            in++;
        } while(in < (*input_iter)->sz);
        input_iter++;
        seg++;
    }
}

int read_input()
{
    char *pinput = (char *) malloc(ALLOC_SIZE);
    size_t res = 0;
    SInputBlock *input_block = NULL;

    do {
        res = fread(pinput, ALLOC_SIZE - 1, 1, stdin);
        if (!ferror(stdin)) {
            pinput[ALLOC_SIZE - 1] = '\0';
            input_block = new SInputBlock();
            input_block->pinput = pinput;
            input_block->sz = ALLOC_SIZE - 1;
            s_state.input.push_back(input_block);
            if (!feof(stdin)) {
                pinput = (char *) malloc(ALLOC_SIZE);
            }
        }
    } while(!ferror(stdin) && !feof(stdin));

    return 0;
}

/*
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
            nsegi++;
            ploc = s_state.input[nsegi]->pinput;
        }
        TRACE("\n");
        iter++;
        i++;
    }
}
*/

int main()
{
    TRACE("1835\n");

    read_input();
    parse_input();
    //trace_blocks();
}
