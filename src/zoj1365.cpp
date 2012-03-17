#include <cstdio>
#include <cstring>

int main()
{
    char line[1024];
    int distance;
    char flightclass[2];
    int mile = 0;

    while(gets(line) != NULL && strcmp(line, "#") != 0)
    {
        if(strcmp(line, "0") == 0)
        {
            printf("%d\n", mile);
            mile = 0;
        }
        else
        {
            // skip two city names
            char* p = strchr(line, ' ');
            p = strchr(p + 1, ' ');
            // read distance and flight clss
            sscanf(p + 1, "%d %s", &distance, flightclass);
            switch(flightclass[0])
            {
                case 'F':
                    distance += distance;
                    break;
                case 'B':
                    distance += (distance % 2? (distance + 1) / 2: distance / 2);
                    break;
                case 'Y':
                    if(distance < 500)
                        distance = 500;
                    break;
                default:
                    break;
            }
            mile += distance;
        }
    }

    return 0;
}
