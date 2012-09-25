#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <math.h>
#include <memory.h>
#include <istream>
#ifndef ONLINE_JUDJE
#include <fstream>
#else
#include <iostream>
#endif

using namespace std;

#ifndef MIN
#define MIN(a, b)   (a < b ? a : b)
#endif

typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;

typedef vector<string> vString;
typedef vString::iterator vStringIter;
typedef list<string *> lString;
typedef lString::iterator lStringIter;
typedef vector<vString *> vvString;
typedef vvString::iterator vvStringIter;

vvString *vvWords;

string decodeWord(string word)
{
    string retVal = "";
    unsigned char length = word.length();
    char dig = 0;

    for(unsigned char i = 0; i < length; i++) {
        switch(word[i]) {
        case 'i' : case 'j' :               dig = '1'; break;
        case 'a' : case 'b' : case 'c' :    dig = '2'; break;
        case 'd' : case 'e' : case 'f' :    dig = '3'; break;
        case 'g' : case 'h' :               dig = '4'; break;
        case 'k' : case 'l' :               dig = '5'; break;
        case 'm' : case 'n' :               dig = '6'; break;
        case 'p' : case 'r' : case 's' :    dig = '7'; break;
        case 't' : case 'u' : case 'v' :    dig = '8'; break;
        case 'w' : case 'x' : case 'y' :    dig = '9'; break;
        case 'o' : case 'q' : case 'z' :    dig = '0'; break;
        default:
            dig = -1;
            break;
        }

        if(dig >= 0) {
            retVal += dig;
        } else {
            break;
        }
    }

    return retVal;
}

template <class type>
void memfill(type *ptr, type value, ulong size)
{
    for(ulong i = 0; i < size; i++) {
        ptr[i] = value;
    }
}

void find()
{
    const ulong CMAX = (INT_MAX / 4);

    ulong   size;
    string  **S;
    bool    *A;
    ulong   *D;
    string   ***C;
    ulong   i;
    ulong   j;
    vStringIter iter;
    ulong   pos;
    ulong   len;
    vString *strs;
    long    w;
    ulong   sum;
    lString result;
    lStringIter resIter;

    size = vvWords->size() + 1;

    S = new string*[size];
    memfill((int *) S, NULL, size);

    A = new bool[size];
    memfill(A, false, size);

    C = new string**[size];
    for(i = 0; i < size - 1; i++) {
        C[i] = new string*[size];
        memfill((int *) C[i], NULL, size);
        strs = (*vvWords)[i];
        len = 0;
        for(iter = strs->begin(); iter != strs->end(); iter++) {
            len = (*iter).length();
            pos = len + i;
            if(pos < size) {
                C[i][pos] = &(*iter);
            }
        }
        
        if(len == 0) {
            A[i] = true;
        }

#ifndef ONLINE_JUDJE
        for(j = 0; j < size; j++) {
            cout << (int)(C[i][j] != NULL);
        }
        cout << endl;
#endif            
    }

    C[i] = new string*[size];
    memfill((int *) C[i], NULL, size);

    
    D = new ulong[size];
    memfill(D, CMAX, size);
    D[0] = 0;

    for(i = 0; i < size; i++) {
        if(A[i] == false) {
            w = -1;
            for(j = 0; j < size; j++) {
                if(false == A[j]) {
                    if(w == -1) {
                        w = j;
                    }

                    if(w != -1 && D[j] < D[w]) {
                        w = j;
                    }
                }
            }

            A[w] = true;

            for(j = 0; j < size; j++) {
                if(NULL != C[w][j]) {
                    sum = (D[w] + (C[w][j] != NULL));
                    if(sum < D[j]) {
                        D[j] = sum;
                        S[j] = C[w][j];
                    }
                }
            }

        }
    }

    sum = D[size - 1];
    if(0 != sum && CMAX != sum) {
        j = size - 1;
        while(sum) {
            result.push_front(S[j]);
            j -= S[j]->length();
            sum--;
        }

        for(resIter = result.begin(), j = 0; resIter != result.end(); resIter++, j++) {
            if(j != 0) {
                cout << " ";
            }
            cout << *(*resIter);
        }
        cout << endl;
    } else {
        cout << "No solution";
    }

    delete[] A;
    delete[] D;
    delete[] S;
    for(i = 0; i < size; i++) {
        delete[] C[i];
    }
    delete[] C;
}

int main()
{
    string phone;
    unsigned char phoneLen;
    unsigned long wordsNum;
    unsigned long i;
    string word;
    string wordDecoded;
    string::size_type pos;

#ifndef ONLINE_JUDJE
    ifstream fin("test.txt");
#endif

#ifndef ONLINE_JUDJE
    fin >> phone;
#else
    cin >> phone;
#endif
    while(phone != "-1") {
        phoneLen = phone.length();

        delete vvWords;
        vvWords = NULL;

        vvWords = new vvString();
        for(i = 0; i < phoneLen; i++) {
            vvWords->push_back(new vString);
        }

#ifndef ONLINE_JUDJE
        fin >> wordsNum;
#else
        cin >> wordsNum;
#endif

        for (i = 0; i< wordsNum; i++) {
#ifndef ONLINE_JUDJE
            fin >> word;
#else
            cin >> word;
#endif
            wordDecoded = decodeWord(word);
            pos = phone.find(wordDecoded, 0);
            while(pos != string::npos) {
                (*vvWords)[(int)pos]->push_back(word);
#ifndef ONLINE_JUDJE
                cout << word << " : " << pos << endl;
#endif
                pos = phone.find(wordDecoded, pos + 1);
            }
        }

        find();

#ifndef ONLINE_JUDJE
        fin >> phone;
#else
        cin >> phone;
#endif
    }

    return 0;
}
