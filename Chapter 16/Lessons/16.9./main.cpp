//vect3.cpp -- методы и итераторы
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
    std::string title;
    int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using namespace std;
    
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
    {
        books.push_back(temp);
    }
    
    if(books.size() > 0)
    {
        cout << "Thank you. You Entered the following "
        << books.size() << " ratings:\n"
        << "Rating\tBook\n";
        
        for_each(books.begin(), books.end(), ShowReview);
        sort(books.begin(), books.end());
        
        cout << "Sorted by title:\nRating\tBook\n";
        
        for_each(books.begin(), books.end(), ShowReview);
        sort(books.begin(), books.end(), worseThan);
        
        cout << "Sorted by rating:\nRating\tBook\n";
        
        for_each(books.begin(), books.end(), ShowReview);
        //random_shuffle(books.begin(), books.end());  //Этой функции больше нету с С++17, вместо нее исп. shuffle(begin, end, g), где g - генератор случаных чисел
        
    }else{
        cout << "No entries. ";
    }
    cout << "Bye!\n";
    return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
    if(r1.title < r2.title)
    {
        return true;
    }else if(r1.title == r2.title && r1.rating < r2.rating)
    {
        return true;
    }else{
        return false;
    }
}

bool worseThan(const Review & r1, const Review & r2)
{
    if(r1.rating < r2.rating)
    {
        return true;
    }else{
        return false;
    }
}


bool FillReview(Review & rr)
{
    std::cout << "Enter book title(q to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
    {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
    {
        return false;
    }
    while(std::cin.get() != '\n')
    {
        continue;
    }
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title <<std::endl;
}
