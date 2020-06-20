#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{   struct State {
        char marker = ' ';
        char text[1000];
    };
    State state;

    cout << "Выполнил студент группы "<<endl;
    cout << "Введите текст"<<endl;
    cin.getline(state.text, sizeof(state.text - 1));

    for (int i = 0; state.text[i] != state.marker; i++)
                if( state.text[i] <= 'z' && state.text[i] >= 'a')
                {
                    state.text[i] += 'A' - 'a';
                    cout << state.text[i] << '\n';
                }
    return 0;
}