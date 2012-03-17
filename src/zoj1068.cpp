#include <iostream>
#include <string>

using namespace std;

class moursecode
{
public:
    string code;
    char letter;
};

int main()
{
    moursecode mourse[30] = 
    {
        {".-",'A'},
        {"-...",'B'},
        {"-.-.",'C'},
        {"-..",'D'},
        {".",'E'},
        {"..-.",'F'},
        {"--.",'G'},
        {"....",'H'},
        {"..",'I'},
        {".---",'J'},
        {"-.-",'K'},
        {".-..",'L'},
        {"--",'M'},
        {"-.",'N'},
        {"---",'O'},
        {".--.",'P'},
        {"--.-",'Q'},
        {".-.",'R'},
        {"...",'S'},
        {"-",'T'},
        {"..-",'U'},
        {"...-",'V'},
        {".--",'W'},
        {"-..-",'X'},
        {"-.--",'Y'},
        {"--..",'Z'},
        {"..--",'_'},
        {".-.-",','},
        {"---.",'.'},
        {"----",'?'}
    };
    int casecount;
    string msg;
    string code;
    string num;

    cin>>casecount;
    for(int i = 0;i<casecount;i++)
    {
        cin>>msg;
        code = num = "";
        for(int index = 0;index<msg.length();index++)
        {
            for(int j = 0;j<30;j++)
            {
                if(mourse[j].letter == msg[index])
                {
                    code += mourse[j].code;
                    num += mourse[j].code.length() + '0';
                    break;
                }
            }
        }

        cout<<i + 1<<": ";
        string temp;
        int start = 0;
        for(int j = num.length() - 1;j>=0;j--)
        {
            temp = code.substr(start,num[j] - '0');
            start += num[j] - '0';
            for(int index = 0;index<30;index++)
            {
                if(mourse[index].code == temp)
                {
                    cout<<mourse[index].letter;
                    break;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
