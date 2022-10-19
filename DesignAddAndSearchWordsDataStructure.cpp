class letterMap
{
public:
    letterMap* NextMap[26];
    bool EndOfWord;
    
    letterMap() {
        memset(NextMap, 0, sizeof(NextMap));
        EndOfWord = false;
    };
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        letterMap* currentMap = &m_FirstMap;
        for(auto character : word)
        {
            char Index = character - 'a';
            if(currentMap->NextMap[Index] != nullptr)
            {
                currentMap = currentMap->NextMap[Index];
            }
            else
            {
                letterMap* dummy =  new letterMap;
                currentMap->NextMap[Index] = dummy;
                currentMap = dummy;
            }
        }
        currentMap->EndOfWord = true;
    }
    
    bool search(string word) {
        return _searchMap(&m_FirstMap, word.c_str());
    }
    
private:
    letterMap m_FirstMap;
    
    bool _searchMap(letterMap* currentMap, const char* character)
    {
        if(character[0] != '\0')
        {
            char Index = character[0] - 'a';
            if(character[0] == '.')
            {
                character++;
                for(int LoopIndex = 0; LoopIndex<26; LoopIndex++)
                {
                    if(currentMap->NextMap[LoopIndex] != nullptr)
                    {
                        if(_searchMap(currentMap->NextMap[LoopIndex], character))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else if(currentMap->NextMap[Index] == nullptr)
            {
                return false;
            }
            else
            {
                return _searchMap(currentMap->NextMap[Index], ++character);
            }
        }
        else
        {
            return currentMap->EndOfWord;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 
 
 
// Version attempted with unordered map. 
// Due to the overhead this turns out to be slower
 
/*
#include <unordered_map>

struct sNextLetters{
    unordered_map<char, sNextLetters*> map;
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        sNextLetters* currentMap = &m_FirstLetter;
        for(auto character : word)
        {
            if(currentMap->map.count(character) == 0)
            {
                sNextLetters* dummy;
                dummy = new sNextLetters;
                currentMap->map[character] = dummy;
                currentMap = dummy;
            }
            else
            {
                currentMap = currentMap->map.at(character);
            }
        }
        {
            char character = '\0';
            if(currentMap->map.count(character) == 0)
            {
                sNextLetters* dummy;
                dummy = new sNextLetters;
                currentMap->map[character] = dummy;
                currentMap = dummy;
            }
            else
            {
                currentMap = currentMap->map.at(character);
            }
        }
    }
    
    bool search(string word) {
        return _searchMap(&m_FirstLetter, word.c_str());
    }
    
private:
    sNextLetters m_FirstLetter;
    
    bool _searchMap(sNextLetters* currentMap, const char* character)
    {
        if(character[0] != '\0')
        {
            if(character[0] == '.')
            {
                character++;
                for(auto entries : currentMap->map)
                {
                    if(_searchMap(entries.second, character))
                    {
                        return true;
                    }
                }
                return false;
            }
            else if(currentMap->map.count(character[0]) == 0)
            {
                return false;
            }
            else
            {
                return _searchMap(currentMap->map.at(character[0]), ++character);
            }
        }
        else
        {
            return currentMap->map.count(character[0]) > 0;
        }
    }
};
*/
