#include <stdio.h>
#include <map>
#include <vector>

#define NLETTERS        ('z' - 'a' + 1)
#define INPUT_MAX       (1000000UL)
#define LETTER_MASK(L)  ( ('.' == L) ? 0 : (L - 'a' + 1) )

using namespace std;

typedef struct {
    unsigned char l;
    unsigned char r;
} lr_base;

typedef union {
    lr_base lr;
    unsigned int int_key;    
} lr_key;

typedef vector<unsigned long> binding_tree;
typedef binding_tree::iterator binding_tree_iter;

typedef struct {
    binding_tree l;
    binding_tree r;
} binding_tree_base;

typedef map<unsigned int, binding_tree_base *> map_binding_trees;
typedef map_binding_trees::iterator map_binding_trees_iter;

typedef enum {
    SEARCH_LOGIN,
    LOGIN,
    SEARCH_DOMAIN,
    DOMAIN
} read_state;

unsigned long g_nemails = 0;
char g_email[INPUT_MAX] = {0};

map_binding_trees g_binding_trees;

binding_tree * add_btree(char l, char r)
{
    lr_key lrkey;
    binding_tree * btree;

    lrkey.lr = {l, r};

    btree = new binding_tree;
    g_binding_trees[lrkey.int_key] = btree;

    return btree;
}

binding_tree * find_btree(char l, char r)
{
    map_binding_trees_iter iter;
    lr_key lrkey;
    binding_tree * btree = NULL;

    lrkey.lr = {l, r};

    iter = g_binding_trees.find(lrkey.int_key);
    if (iter != g_binding_trees::npos) {
        btree = iter.second;
    }

    return btree;
}

unsigned long calc_new_combs(binding_tree *btree, char l, char r, unsigned long lpos, rpos)
{
    unsigned long out = 0;
    unsigned long mask;
    unsigned long binding;

    if (l == 0) {
        /*r*/
        binding = btree->r[pos];
        mask = LETTER_MASK(r);
        if (0 == binding & mask) {
            btree->r[pos] |= mask;
            out += (lpos + 1);
        }
    } else if (r == 0) {
        /*l*/
        binding = btree->l[pos];
        mask = LETTER_MASK(l);
        if (0 == binding & mask) {
            btree->l[pos] |= mask;
            out += (rpos + 1);
        }
    } else {
        /*l&r*/
        binding = btree->l[pos];
        mask = LETTER_MASK(l);
        if (0 == binding & mask) {
            btree->l[pos] |= mask;
            out += (rpos + 1);
        }
    }
}

void process_email(char *s, char *at, char *e)
{
    if (s == e) {
        printf("e == s\n");
        return;
    }

    do {        
        printf("%c", s == at ? '|' : *s);
        s++;
    } while (s <= e);
    
    printf("\n");
}

inline int isletter(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

inline int validate_ch(char ch, char prev_ch)
{
    return (('.' == ch && isletter(prev_ch)) || isletter(ch));
}

void read_input(void)
{
    char *pin = NULL;
    char *pemail_start = NULL;
    char *pemail_end = NULL;
    char *pdomain_start = NULL;
    read_state rstate = SEARCH_LOGIN;
    char prev_ch = 0;

    pin = g_email;
    while ((*pin = getchar()) != EOF) {
        if ('\n' == *pin) {
            if (rstate == DOMAIN) {
                process_email(pemail_start, pdomain_start - 1, pemail_end);
            }
            pin = g_email;
            rstate = SEARCH_LOGIN;
        } else if (rstate == SEARCH_LOGIN) {
            if (validate_ch(*pin, prev_ch)) {
                pemail_start = pin;
                rstate = LOGIN;
            }
        } else if (rstate == LOGIN) {
            if ('@' == *pin) {
                rstate = SEARCH_DOMAIN;
            } else if (!validate_ch(*pin, prev_ch)) {
                rstate = SEARCH_LOGIN;
            }
        } else if (rstate == SEARCH_DOMAIN) {
            if (isletter(*pin)) {
                rstate = DOMAIN;
                pdomain_start = pin;
                pemail_end = pin;
            } else {
                rstate = SEARCH_LOGIN;
            }
        } else if (rstate == DOMAIN) {
            if ('@' == *pin) {
                process_email(pemail_start, pdomain_start - 1, pemail_end);
                if (isletter(prev_ch)) {
                    pemail_start = pdomain_start;
                    rstate = SEARCH_DOMAIN;
                } else {
                    rstate = SEARCH_LOGIN;
                }
            } else if (!validate_ch(*pin, prev_ch)) {
                process_email(pemail_start, pdomain_start - 1, pemail_end);
                rstate = SEARCH_LOGIN;
            } else if (isletter(*pin)) {
                pemail_end = pin;
            }
        }
        prev_ch = *pin++;
    }
}

int main(void)
{
    read_input();

    return 0;
}
