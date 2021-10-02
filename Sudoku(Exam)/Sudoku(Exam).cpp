// Sudoku(Exam).cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>  //For input and output
#include<ctime>               //To fill columns and rows randomly       //for text color        //for _getch()
#include<string>
#include<vector>
#include<algorithm>



using std::cout;
using std::cin;

bool compare(int a, int b) {
    return a < b;
}



class Cell {
    int number;
   bool state;
public:
    int getNumber() const;
    bool getState() const;
    Cell& operator=(int c);
    bool operator<(Cell& oper1);
    operator int();
    bool operator!=(Cell& operand);
    
};

int Cell::getNumber() const {
    return number;
}
bool Cell::getState() const {
    return state;
}
Cell& Cell::operator=(int c) {
    number = c;
    state = true;

    return *this;
}
bool Cell::operator<(Cell& oper1) {
    return number < oper1.number;
}

Cell::operator int() {
    return number;
}

bool Cell::operator!=(Cell& operand) {
    return number != operand.getNumber();
}
//Output for cells:

std::ostream& operator<<(std::ostream& str, Cell& cell){ 
    if (cell.getState() == false)
        return str << (char)223;
    else if (cell.getState() == true)
        return str << cell.getNumber();
}

class Grid{
 
    std::vector<Cell> field;
    
    const int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
public:
    Grid(int level){
        
        
            field.resize(81);
            int f = 1;
            for (int i = 0; i < 81; i++) {
                
                   
                    /*while (field[i] != field[i + 1] || field[i] != field[i + 2] || field[i] != field[i + 3] ||
                        field[i] != field[i + 4] || field[i] != field[i + 5] || field[i] != field[i + 6] || field[i] != field[i + 7] ||
                        field[i] != field[i + 8]) {*/
                        field[i] = f;
                        f++;
                        if (f == 10) {
                            f = 1;
                        }
                        if (i == 9 || i == 18 || i == 27 || i == 36
                        || i == 45 || i == 54 || i == 63 || i == 72
                        || i == 81) {

                            std::sort(begin(field) + i - 9, begin(field) + i);
                        }
                     
                    
                }
                //std::random_shuffle(field.begin(), field.end());
            }
        
    
    
    void Print(int level) {
        
           
                for (auto i = begin(field); i < end(field); ++i) {
                cout << *i << " ";
                if (i == begin(field) + 3 - 1 || i == begin(field) + 6 - 1 || i == begin(field) + 9 - 1 || i == begin(field) + 12 - 1 || i == begin(field) + 15 - 1 || i == begin(field) + 18 - 1 || i == begin(field) + 21 - 1 || i == begin(field) + 24
                    - 1 || i == begin(field) + 27 - 1 || i == begin(field) + 30 - 1 || i == begin(field) + 33 - 1 || i == begin(field) + 36 - 1 || i == begin(field) + 39 - 1 || i == begin(field) + 42 - 1 || i == begin(field) + 45 - 1 || i == begin(field) + 48 - 1
                    || i == begin(field) + 51 - 1 || i == begin(field) + 54 - 1 || i == begin(field) + 57 - 1 || i == begin(field) + 60 - 1 || i == begin(field) + 63 - 1 || i == begin(field) + 66 - 1 || i == begin(field) + 69 - 1 || i == begin(field) + 72 - 1 ||
                    i == begin(field) + 75 - 1 || i == begin(field) + 78 - 1 || i == begin(field) + 81 - 1)
                    cout << "\t";
                if (i == begin(field) + 9 - 1 || i == begin(field) + 18 - 1 || i == begin(field) + 27 - 1 || i == begin(field) + 36 - 1
                    || i == begin(field) + 45 - 1 || i == begin(field) + 54 - 1 || i == begin(field) + 63 - 1 || i == begin(field) + 72 - 1)
                    cout << "\n";
                if (i == begin(field) + 27 - 1 || i == begin(field) + 54 - 1 || i == begin(field) + 81)
                    cout << "\n\n";
            }
        
        }
   
    
};

int main()
{
    srand(time(0));
    int l;    //level
    std::cout << "SUDOKU:\n\n";
    std::cout << "Enter level: \n";
    std::cout << "0 - easy\n";
    std::cout << "1 - medium\n";
    std::cout << "2 - hard\n";
    std::cin >> l;
    system("cls");
    Grid grids(l);
    grids.Print(l);
    cout << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
