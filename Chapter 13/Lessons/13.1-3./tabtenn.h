//tabtenn0.h -- базовый класс для клуба настольного тенниса
#ifndef TABTENN_HPP_
#define TABTENN_HPP_

#include <string>
using std::string;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn, const string & ln, bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;}
    void ResetTable(bool v) { hasTable = v;}
};

#endif
