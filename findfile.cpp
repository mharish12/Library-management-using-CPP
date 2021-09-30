#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

class Book
{
    const double PENALITY = 1.5;
    const int MAX_LOAN = 15;

private:
    /* data */
    char m_title[51];
    int m_sku;
    int m_daysOnLoan;

public:
    void set(string book_title, int sku, int nDays)
    {
        if (book_title == "")
        {
            setEmpty();
        }
        else
        {
            int i = 0;
            for (i = 0; i < book_title.size(); i++)
            {
                m_title[i] = book_title[i];
            }
            m_title[i] = '\0';
        }
        if(sku>0){
            m_sku=sku;
        }
        else{
            m_sku=0;
        }
        if(m_daysOnLoan>0){
            m_daysOnLoan=nDays;
        }
        else{
            m_daysOnLoan=0;
        }
    }
    void setEmpty()
    {
        m_title[0] = '\0';
    }
    bool hasPenality()
    {
        if (m_daysOnLoan > MAX_LOAN)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (m_title[0] == '\0')
        {
            return true;
        }
        return false;
    }
    bool subTitle(string subString)
    {
        int n = 0;
        while (m_title[n])
            n++;
        int m = sizeof(subString) / sizeof(subString[0]);
        int k = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            flag = true;
            for (int j = 0; j < m && flag; j++)
            {
                k = i;
                if (m_title[k] == subString[j])
                {
                    k++;
                }
                else
                {
                    flag = false;
                }
            }
            if (flag == true)
            {
                return true;
            }
        }
        return false;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Invalid library book" << endl;
        }
        else
        {
            cout << left << m_title << endl;
        }
    }
};


class Library{
    private:
    char m_name[30];
    vector<Book> m_books;
    int m_sizeOfBooksArray;
    int m_addedBooks=0;
    void setEmpty(){
        m_name[0]='\0';
    }
    bool isEmpty(){
        if(m_name[0]=='\0'){
            return true;
        }
        return false;
    }
    void header(const char* title){
        for(int i=0;i<78;i++){
            cout<<"-";
        }
        cout<<endl;
        cout<<"***** "<<m_name<<" *****"<<endl;
        cout<<title<<endl;
        for(int i=0;i<78;i++){
            cout<<"-";
        }
        cout<<endl;
        cout<<"Row Book title";//14 characters
        cout<<"                                       ";//39 characters
        cout<<"sku    loan days penality"<<endl;//25 characters total 78 characters
        cout<<"--- ---------------------------------------- ------- -------- -------"<<endl;
        
    }
    void footer(){
        for(int i=0;i<78;i++){
            cout<<"-";
        }
        cout<<endl;
    }
    public:
    void initialize(const char* name, int noOfBooks){
        if(name[0]!='\0'){
            int i = 0;
            int  m= 0;
            while(name[m])
            m++;
            for (i = 0; i < m; i++)
            {
                m_name[i] = name[i];
            }
            m_name[i] = '\0';
        }
        if (noOfBooks>0){
            m_sizeOfBooksArray= noOfBooks;
        }
        else{
            m_sizeOfBooksArray=0;
        }     
        
    }
    bool addBook(const char* book_title,int sku,int loanDays){
        Book book;
        if(m_addedBooks<=m_sizeOfBooksArray){
            book.set(book_title,sku,loanDays);
        }
        if(!book.isEmpty()){
            m_addedBooks++;
            return true;
        }
        return false;

    }
    void clear(){
        m_books.clear();
    }
    void display(const char* substr){
        cout<<">>> Searching for: \"";
        cout<<substr;
        cout<<"\" <<<"<<endl;
        int c=0;
        header(substr);
        for(int i=0;i<m_books.size();i++){
            if(m_books[i].subTitle(substr)){
               cout<<"    ";
               m_books[i].display(); 
               c++;
            }
        }
        if(c==0){
            cout<<"No book title contains \""<<substr<<" value\""<<endl;
        }
        footer();
    }
    void display(bool overdueOnly=false){
        if(overdueOnly){
            header("Overdue Books");
            int rowNumber=1;
            for(int i=0;i<m_books.size();i++){
            {
                if(m_books[i].hasPenality()){
                    cout<<rowNumber++<<"    ";
                    m_books[i].display();
                }
            }
            footer();
        }
        }
        else{
            header("Books in Loan");
        }
        
    }

};

int main()
{
   
}
