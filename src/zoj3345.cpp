#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(const string& str, char delimiter)
{
    vector<string> tokens;
    string buffer;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == delimiter)
        {
            if(buffer.length() > 0)
            {
                tokens.push_back(buffer);
                buffer.clear();
            }
        }
        else
            buffer.push_back(str[i]);
    }
    if(buffer.length() > 0)
        tokens.push_back(buffer);
    return tokens;
}

class Lang
{
    public:
        Lang(const string& langname): name(langname) {}

        const string& getLangName() const
        {
            return name;
        }

        void addWord(const string& word, const string& type)
        {
            vocabulary.insert(pair<string, string>(word, type));
        }

        void clearVocabulary()
        {
            vocabulary.clear();
        }

        void addPattern(const string& pattern)
        {
            patterns.push_back(split(pattern, ' '));
        }

        bool match(const string& sentence) const
        {
            const vector<string> tokens = split(sentence, ' ');

            for(vector<vector<string> >::const_iterator pattern = patterns.begin(); pattern != patterns.end(); pattern++)
            {
                if(matchPattern(tokens, *pattern))
                    return true;
            }
            return false;
        }

    private:

        bool matchPattern(const vector<string> tokens, const vector<string> pattern) const
        {
            if(tokens.size() != pattern.size())
                return false;

            int i;
            pair<multimap<string, string>::const_iterator, multimap<string, string>::const_iterator> words;
            multimap<string, string>::const_iterator iter;
            for(i = 0; i < tokens.size(); i++)
            {
                if(tokens[i] != pattern[i])
                {
                    words = vocabulary.equal_range(tokens[i]);
                    for(iter = words.first; iter != words.second; iter++)
                    {
                        if(iter->second == pattern[i])
                            break;
                    }
                    if(iter == words.second)
                        return false;
                }
            }
            return true;
        }

        string name;
        multimap<string, string> vocabulary;
        vector<vector<string> > patterns;
};

int main()
{
    int t;
    int m, n;
    int i;
    string langname, type, word;
    string sentence;

    const int langcount = 4;
    Lang langs[langcount] = { Lang("German"), Lang("Japanese"), Lang("English"), Lang("Chinese") };
    langs[0].addPattern("Ich habe ein [n]");
    langs[0].addPattern("Ich bin [n]");
    langs[0].addPattern("Ich heisse [n]");
    langs[0].addPattern("Du hast [n]");
    langs[1].addPattern("[pn] ha [n] desu");
    langs[1].addPattern("[pn] ha [n] da");
    langs[1].addPattern("[pn] ha [n] ga [adj] desu");
    langs[1].addPattern("[n] saikou");
    langs[1].addPattern("yoi otoshiwo");
    langs[2].addPattern("[pn] [vi]");
    langs[2].addPattern("[pn] [vt] [n]");
    langs[2].addPattern("There is a [n]");
    langs[2].addPattern("Happy new year");
    langs[3].addPattern("[pn] shi [n]");
    langs[3].addPattern("[pn] [vi]");
    langs[3].addPattern("[pn] [vt] [n]");
    langs[3].addPattern("ni hao");

    cin >> t;
    for(int k = 0; k < t; k++)
    {
        for(i = 0; i < langcount; i++)
            langs[i].clearVocabulary();

        cout << "Case #" << k + 1 << ":" << endl;
        cin >> n >> m;
        while(n--)
        {
            cin >> langname >> type >> word;
            for(i = 0; i < langcount; i++)
            {
                if(langname == langs[i].getLangName())
                {
                    langs[i].addWord(word, type);
                    break;
                }
            }
        }
        getline(cin, sentence);
        while(m--)
        {
            getline(cin, sentence);
            for(i = 0; i < langcount; i++)
            {
                if(langs[i].match(sentence))
                {
                    cout << langs[i].getLangName() << endl;
                    break;
                }
            }
            if(i == langcount)
                cout << "I don't know." << endl;
        }
    }
    return 0;
}

