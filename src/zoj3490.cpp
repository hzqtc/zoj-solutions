#include <cstdio>
#include <cstring>

using namespace std;

int isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

int isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int isDigit(char c)
{
    return c >= '0' && c <= '9';
}

class IncStr
{
    public:
        IncStr(char* str): s(str) { }

        char* increase()
        {
            int i;
            int pos = -1;
            for(i = strlen(this->s) - 1; i >= 0; i--)
            {
                if(isDigit(this->s[i]))
                {
                    if(this->s[i] == '9')
                    {
                        this->s[i] = '0';
                        pos = i;
                    }
                    else
                    {
                        this->s[i]++;
                        break;
                    }
                }
                else if(isLower(this->s[i]))
                {
                    if(this->s[i] == 'z')
                    {
                        this->s[i] = 'a';
                        pos = i;
                    }
                    else
                    {
                        this->s[i]++;
                        break;
                    }
                }
                else if(isUpper(this->s[i]))
                {
                    if(this->s[i] == 'Z')
                    {
                        this->s[i] = 'A';
                        pos = i;
                    }
                    else
                    {
                        this->s[i]++;
                        break;
                    }
                }
            }
            if(i < 0)
            {
                if(pos < 0)
                    this->s[strlen(this->s) - 1]++;
                else
                {
                    switch(this->s[pos])
                    {
                        case '0':
                            this->insert('1', pos);
                            break;
                        case 'a':
                            this->insert('a', pos);
                            break;
                        case 'A':
                            this->insert('A', pos);
                            break;
                    }
                }
            }
            return this->s;
        }

        const char* getStr() const
        {
            return this->s;
        }

    private:
        void insert(char c, int offset)
        {
            for(int i = strlen(this->s); i >= offset; i--)
                this->s[i + 1] = this->s[i];
            this->s[offset] = c;
        }

        char* s;
};

int main()
{
    int t;
    const int LEN = 128;
    char str[128];
    int n;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %d", str, &n);
        IncStr incstr(str);
        while(n--)
        {
            incstr.increase();
            printf("%s\n", incstr.getStr());
        }
        printf("\n");
    }
    return 0;
}
