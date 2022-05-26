#include <iostream>

using namespace std;

int main()
{
    int num; // размер массива
    cout << "Enter integer value: ";
    cin >> num; // получение от пользователя размера массива

    int *f_darr = new int[num]; // Выделение памяти для массива
    int *s_darr = new int[num];
    int *th_darr = new int[2*num];
    for (int i = 0; i < num; i++) {
        // Заполнение массива и вывод значений его элементов
        f_darr[i] = rand() % 15 +1;
	s_darr[i] = rand() % 15 +1;
        //cout << "Value of first " << i << " element is " << f_darr[i] << endl;
	//cout << "Value of second " << i << " element is " << s_darr[i] << endl;
    }

    cout << "first massiv " ;
    for (int i = 0; i < num; i++)
        cout << f_darr[i] << " ";
    cout << endl;

    cout << "second massiv ";
    for (int i = 0; i < num; i++)
        cout << s_darr[i] << " ";
    cout << endl;

    asm(
        "movq %[f], %%rax;"
        "movq %[s], %%rbx;"
        "movq %[th], %%rdx;"
        "movl %[num], %%ecx;"


    "tmp:"
        "movl (%%rax), %%esi;"
        "movl %%esi, (%%rdx);"
        "addq $4, %%rdx;"
        "addq $4, %%rax;"

        "movl (%%rbx), %%esi;"
        "movl %%esi, (%%rdx);"
        "addq $4, %%rbx;"
        "addq $4, %%rdx;"

        "loop tmp;"
        :
        :[num]"m"(num), [f]"m"(f_darr), [s]"m"(s_darr), [th]"m"(th_darr)
        :
    );

    for (int i = 0; i < num * 2; i++) 
        cout << th_darr[i] << " ";
    cout << endl;


    delete [] f_darr; 
    delete [] s_darr;
    delete [] th_darr; // очистка памяти
    return 0;
}
