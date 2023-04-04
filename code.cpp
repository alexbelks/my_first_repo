#include <iostream>
#include <limits>

using namespace std;

unsigned short input_unsigned_short(const char* s) 
{
    short x;
    cout << s;
    cin >> x;
    while (cin.fail() || cin.rdbuf()->in_avail() > 1) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error!!! Retry get_three_number: ";
        cin >> x;
    };
    return x;
};

bool check_numbers(int T, int D, int N) 
{
    /* Проверяет, не превышают ли числа своих максимальных значений */
    return ((T <= 3) &&  // 3 - максимальное число, потому что может быть число только 2 битное (и его диапозон 0..3)
            (D <= 1) && 
            (N <= 511));
}

unsigned short compose_three_to_one(unsigned short T, unsigned short D, unsigned short N) {
    /* Создание ответа для 6 варианта */
    unsigned short answer = 13 << 12;
    answer |= (T << 10);
    answer |= (D << 9);
    answer |= N;
    return answer;
};

void get_three_number(unsigned short &T, unsigned short &D, unsigned short &N) {
    do { // Заставляем пользолвателя вводить числа, пока оно не станет подходить
        cout << "Please give me correct numbers" << endl;
        T = input_unsigned_short("T [0; 3]: ");
        D = input_unsigned_short("D [0; 1]: ");
        N = input_unsigned_short("N [0; 511]: ");
    } while (!check_numbers(T, D, N));
};

void print_numders(int A)
{
    cout << hex << A << dec << endl;
    cout << ((A >> 10) & 3) << " ";
    cout << ((A >> 9) & 1) << " ";
    cout << ((A >> 0) & 511) << endl;
}
