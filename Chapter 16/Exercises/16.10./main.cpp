//vect3.cpp -- методы и итераторы
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool SortRating(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool SortPrice(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> & rr);
void MainMenu();

int main()
{
    using namespace std;
    
    vector< shared_ptr<Review> > books;
    Review temp;
    while(FillReview(temp))
    {
        shared_ptr<Review> tr(new Review);
        tr -> title = temp.title;
        tr -> price = temp.price;
        tr -> rating = temp.rating;
        books.push_back(tr);
    }
    
    if(books.size() > 0)
    {
        MainMenu();
        int choice;
        while(cin >> choice && choice != 6)
        {
            switch(choice)
            {
                case 1: std::cout << "Rating\tTitle\tPrice $\n";
                        for_each(books.begin(), books.end(), ShowReview);           //в исходном порядке
                        MainMenu();
                        break;
                case 2: sort(books.begin(), books.end());                           //по убыванию рейтинга
                        std::cout << "Rating\tTitle\tPrice $\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        MainMenu();
                        break;
                case 3: sort(books.begin(), books.end(), SortRating);               // по возрастанию рейтинга
                        std::cout << "Rating\tTitle\tPrice $\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        MainMenu();
                        break;
                case 4: sort(books.begin(), books.end(), SortPrice);                //по возрастанию цены
                        std::cout << "Rating\tTitle\tPrice $\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        MainMenu();
                        break;
                case 5: sort(books.rbegin(), books.rend(), SortPrice);              // по убыванию цены
                        std::cout << "Rating\tTitle\tPrice $\n";
                        for_each(books.begin(), books.end(), ShowReview);
                        MainMenu();
                        break;
                default: cout << "Wrong input. Try again.\n";
                        MainMenu();
                        break;
            }
        }
        
    }else{
        cout << "No entries. ";
    }
    cout << "Bye!\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1 -> title < r2 -> title)
    {
        return true;
    }else if(r1 -> title == r2 -> title && r1 -> rating < r2 -> rating)
    {
        return true;
    }else if(r1 -> title == r2 -> title && r1 -> rating == r2 -> rating && r1 -> price < r2 -> price) {
        return true;
    }else{
        return false;
    }
}

bool SortRating(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1 -> rating < r2 -> rating)
    {
        return true;
    }else{
        return false;
    }
}
bool SortPrice(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1 ->price < r2 -> price)
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
    if(rr.title == "quit" || rr.title == "q")
    {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
    {
        return false;
    }
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
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

void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr -> rating << "\t" << rr -> title << "\t" << rr -> price << std::endl;
}
void MainMenu()
{
    std::cout << "Sort books by:\n1)Original order\t2)By Title\n3)By Rating\t4)By Price(increase)\n5)By Price(decrease)\t6)Quit\n";
}
