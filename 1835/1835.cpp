#include <stdio.h>
#include <map>
#include <vector>

#define NLETTERS        ('z' - 'a' + 1)
#define INPUT_MAX       ()

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

typedef map<unsigned int, binding_tree_base> map_binding_trees;
typedef map_binding_trees::iterator map_binding_trees_iter;

typedef enum {
    SEARCH_LOGIN,
    LOGIN,
    SEARCH_DOMAIN,
    DOMAIN
} read_state;

unsigned long g_nemails = 0;
char g_email[1000000UL] = {0};

inline int isletter(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

inline int validate_ch(char ch, char prev_ch)
{
    return (('.' == ch && isletter(prev_ch)) || isletter(ch));
}

void process_email(char *s, char *e)
{
    if (s == e) {
        printf("e == s\n");
        return;
    }

    do {
        printf("%c", *s++);
    } while (s <= e);
    
    printf("\n");
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
                process_email(pemail_start, pemail_end);
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
                process_email(pemail_start, pemail_end);
                if (isletter(prev_ch)) {
                    pemail_start = pdomain_start;
                    rstate = SEARCH_DOMAIN;
                } else {
                    rstate = SEARCH_LOGIN;
                }
            } else if (!validate_ch(*pin, prev_ch)) {
                process_email(pemail_start, pemail_end);
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
