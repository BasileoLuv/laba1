#include <iostream>
#include <fstream>

using namespace std;

const char input[] = "input.txt";
const char output[] = "output.txt";
const int MAX_SIZE = 200;

struct String
{
public:
    void addChar(const char & inputChar) {
        if (inputChar == '\n') {
            return;
        }

        this->text[this->index] = inputChar;
        this->index++;
    }
    bool isMarker(const char & inputChar) {
        return inputChar == this->marker;
    }
    void saveToFile(const string& outputFileName) {
        ofstream outputFile(outputFileName, ios_base::app);

        if (outputFile.is_open()) {
            int i = 0;

            while (i <= this->index) {
                outputFile << this->text[i];

                if (this->isMarker(this->text[i])) {
                    break;
                }

                i++;
            }

            outputFile << endl;
            outputFile.close();
        }
    };

private:
    char text[MAX_SIZE]{};
    int index = 0;
    char marker = '@';
};


int main () {

    ifstream inputFile(input);

    ofstream clearFile(output, ios_base::trunc);
    clearFile.close();
    {
        cout << "Выполнил студент группы 9005 Басилая Андрей "<<endl;
        //cout << "Введите текст:"<<endl;
        String line;
        char string[80], replace[80], found[80], str1[80], str2[80], str3[80] ;
        cout << "\nEnter string(max 3 words)\n" ;
        cin.getline(string , 80);

        cout <<"\nВ каких слова(х) увеличить буквы \n"      ;
        cin.getline(replace , 80);
        for(int i=0; i<replace[0]; i++)
            if( replace[i] <= 'z' && replace[i] >= 'a')
            {
                replace[i] += 'A' - 'a';
            }
        cout << replace;

       // strreplace(string,  replace);
        if (inputFile.is_open()) {
            char inputChar;
            //char n[30];
            std::ofstream out;          // поток для записи
            out.open("input.txt"); // окрываем файл для записи
            if (out.is_open()) {
//
 //           cin.getline(n, 30);
//                cout << n;
//
//                for(int i=0; i<n[i]; i++)
//                    if( n[i] <= 'z' && n[i] >= 'a')
//                    {
//                        n[i] += 'A' - 'a';
//
//                    }
                out << replace << std::endl;
                out << "--------\n" << std::endl;
                out << "Изначальный текст:" << string << std::endl;
                out << "--------\n" << std::endl;

//
                while (inputFile  >> inputChar ) {

                    line.addChar(inputChar);
                }


               line.addChar('@');
                inputFile.close();
            }
            line.saveToFile(output);

        }

    }
}

