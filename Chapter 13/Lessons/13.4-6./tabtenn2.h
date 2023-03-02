//tabtenn0.h -- базовый класс для клуба настольного тенниса
#ifndef TABTENN2_HPP_
#define TABTENN2_HPP_

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


// простой производный класс
class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() {return rating;}
    void ResetRating(unsigned int r) {rating = r;}
};


#endif
