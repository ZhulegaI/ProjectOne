

#include <iostream>
#include <stdio.h>
#include <clocale>
#include<bitset>


using namespace std;

void poisk(unsigned short n, unsigned short &edd, unsigned short &null) {
    const unsigned short num = 4; /* Константа для просмотра определённой области 
                                  (в двоичном коде 100)*/
    while (n >=1) {
        if ((n % num) == 3) {
            edd++;
            n >>= 2;// Отсекает 2 бита
        }
        else
            if ((n % num) == 0) {
                null++;
                n >>= 2;
            }
            else n >>= 1;// Отбрасывает младший бит
 
    }


}

void main()
{
    setlocale(LC_CTYPE, "rus");
    unsigned short edd = 0, null = 0, n;

    cout << "Введите число не большее чем 255 и не меньшее 0!\n";
    cin >> n;
    cout << endl << "Ваше число в 2-ой системе счесления:\t" << bitset<8> (n) << endl;
    poisk(n, edd, null);

    cout << "Кол-во парных едениц:\t" << edd << endl;
    cout << "Кол-во парных нулей:\t" << null << endl;

}
