#include <stdio.h>
#include <string.h>

#define NAME_MAX    (30)
#define N_MAX       (100)

typedef struct {
    int hash;
    char name[NAME_MAX + 1];
    int repeated;
} CacheNode_T;

int main(void) 
{
    int N = 0;
    char name[NAME_MAX + 1] = {0};
    int hash;
    CacheNode_T cache[N_MAX];
    int idxCacheLast = 0;
    int idxCacheCurr = 0;
    int len;
    int idxStr;
    char fFound;
    
    scanf("%d", &N);
    if (N > N_MAX || N < 1) {
        return 0;
    }

    while (EOF != scanf("%s", &name)) {
        hash = len = strlen(name);
        for (idxStr = 0; idxStr < len; idxStr++) {
            hash = ((hash << 5) ^ (hash >> 27) ^ name[idxStr]);
        }

        fFound = 0;
        for (idxCacheCurr = 0; idxCacheCurr < idxCacheLast && !fFound; idxCacheCurr++) {
            if (cache[idxCacheCurr].hash == hash) {
                if (!strncmp(cache[idxCacheCurr].name, name, NAME_MAX)) {
                    cache[idxCacheCurr].repeated++;
                    fFound = 1;
                }
            }
        }

        if (!fFound) {
            cache[idxCacheLast].hash = hash;
            strncpy(cache[idxCacheLast].name, name, NAME_MAX);
            cache[idxCacheLast].name[NAME_MAX] = '\0';
            cache[idxCacheLast].repeated = 1;
            idxCacheLast++;
        }
    }   

    for (idxCacheCurr = 0; idxCacheCurr < idxCacheLast; idxCacheCurr++) {
        if (cache[idxCacheCurr].repeated > 1) {
            printf("%s\n", cache[idxCacheCurr].name);
        }
    }

    return 0;
}
