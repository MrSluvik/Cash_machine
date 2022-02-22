﻿//Банкомат містить в достатній кількості купюри номіналом 10, 20, 50, 100, 200 і 500 гривень. 
//Знайти найменшу кількість купюр, якою можна видати суму в n гривень, або вивести -1, якщо вказану суму видати не можна.
//вводиться число n (1 ≤ n ≤ 10^6).
//Єдиною умовою є зчитування даних з файлу і запис даних в файл
#include <iostream>
#include<Windows.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int a = 6;
    int money[a] = { 500, 200, 100, 50, 20, 10 };//масив доступних купюр
    int  sum=0, p=0, k=0; 
    ifstream fileIn;
    fileIn.open("D:/Users8/Я/Desktop/text.txt");//відкриття файлу за шляхом до нього
    int c = 0;
    fileIn >> c;//запис в зміну с число з файлу "D:/Users8/Я/Desktop/text.txt"
    if ((1 <= c )and (c <= 1000000)) {//перевірка чи введенно допустиме значення ,за умовою
        if (c % 10 == 0)//перевірка чи число можливо видати доступними купюрами
        {
            while (sum != c)
            {
                sum += money[p];//додаєм купюри
                k++;
                if (sum > c)//перевірка чи нова сума  більша за стару
                {
                    sum -= money[p];//віднімаємо купурю яку додали
                    k--;//віднімаємо від кількості купур останню додану
                    p++;//переходимо не меншої купюри
                }
            }
            cout << k << endl;//вивід мінімальної кількості купюр в консоль
            fileIn.close();//закриття файлу

        }
        else {
            cout << -1 << endl;////вивід повідомлення про неможливість видачі суми в консоль
            fileIn.close();//закриття файлу

        }
        if (k == 0) {
            ofstream fileOut;                                             
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);   //відкриття файлу за шляхом до нього
            fileOut << "\nНеможливо видати вказану суму " << -1;         //запис в файл про неможливість видачі суми
            fileOut.close();//закриття файлу
        }
        else {
            ofstream fileOut;                                                  
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);        //відкриття файлу  за шляхом до нього  
            fileOut << "\nНайменша кількість купюр яку можна видати = " << k; //запис в файл про можливість видачі суми
            fileOut.close();//закриття файлу
        }
    }
    else {
        cout << "Вказана зантто велика або занатто мала сума"<<endl;

        ofstream fileOut;                                          
        fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);//відкриття файлу за шляхом до нього
        fileOut << "\nВказана зантто велика або занатто мала сума";//запис в файл , що вказана мала обо натто велика сума
        fileOut.close();//закриття файлу
    }
    
    return 0;
}

