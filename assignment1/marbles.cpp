#include <iostream>
#include <random>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

int rand_num() {

    std::random_device rd;
    std::default_random_engine generator(rd());

    std::uniform_int_distribution<int> distribution(1, 20);

    int random_number = distribution(generator);

    return random_number;
}

int main() {

    int blue_marbles = rand_num();
    int green_marbles = rand_num();
    int pink_marbles = rand_num();
    int orange_marbles = rand_num();

    while(true) {
        int input_1 = 0;
        int input_color = 0;
        int input_n = 0;

        printf("you have %i blue marbles, %i green marbles, %i pink marbles, and %i orange marbles. \n"
            , blue_marbles, green_marbles, pink_marbles, orange_marbles);

        cout << "you can: " << endl << "1. add marbles" << endl <<"2. remove marbles"
            << endl <<"3. quite" << endl << "enter a number: ";
        cin >> input_1;

        if(input_1 ==3) {
            break;
        }

        else if (input_1 != 1 && input_1 != 2) {
            continue;
        }

        cout << "what color marbles: " << endl <<
            "1. blue" << endl << "2. green" << endl << "3. pink" << endl << "4. orange" << endl;
        cin >> input_color;

        if (input_1 == 1) {
            cout << "how many marbles would u like to add: ";
            cin >> input_n;
            if (input_color == 1 ) {
                blue_marbles += input_n;
            }
            else if (input_color == 2) {
                green_marbles += input_n;
            }
            else if (input_color == 3) {
                pink_marbles += input_n;
            }
            else if (input_color == 4) {
                orange_marbles += input_n;
            }
            else {
                cout << endl << endl <<"input not recognized" << endl << endl;
            }

        }
        else if (input_1 == 2) {
            cout << "how many marbles would u like to remove: ";
            cin >> input_n;
            if (input_color == 1 ) {
                blue_marbles -= input_n;
            }
            else if (input_color == 2) {
                green_marbles -= input_n;
            }
            else if (input_color == 3) {
                pink_marbles -= input_n;
            }
            else if (input_color == 4) {
                orange_marbles -= input_n;
            }
            else {
                cout << endl << endl <<"input not recognized" << endl << endl;
            }
            
        }
    }

    cout << "bye bye";
    return 0;
}

