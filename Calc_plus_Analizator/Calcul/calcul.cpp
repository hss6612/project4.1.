#include "mainwindow.h"
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QString>
using namespace std;
string s="",buf="";									//Арифметическая строка и буфер для хранения
int p=0;				//Указатель для строки с арифметическими данными
bool Log=true,ErrorZero;
const int R=100;
struct stack			// структура для стэка
{
        double d[R+1];
        int size;
};
bool Skob(string s)
{
        int c=0;
        for(unsigned int i=0;i<s.size();i++)
        {
                if(s[i]=='(')
                        c++;
                if(s[i]==')')
                        c--;
        }
        if (c==0)
                return true;
        else
                return false;
}
void Smes(stack *t,int p)			//Функция для смещения элементов стэка
{
        for (int i=p;i<=t->size-1;i++)
        {
                t->d[i]=t->d[i+1];
        }
        t->size--;
}
void ReseT(stack *T)			// Иницилизация стэков для знаков операций и чисел
{
        T->size=0;
        for (int i=1;i<=R;i++)
        {
                T->d[i]=-1;
        }
}
double Rezult(stack *c,stack *z)		//Функция подсчета арифметических действий с использованием стеков
{
    if(ErrorZero==true)
        return 0;
        while(z->size!=0)			// выход по обнулению стэка арифметических знаков
        {
                int i=1;
                while(i<=z->size)
                {
                        if ((z->d[i]==1)||(z->d[i]==2))			//Нахождение умножения или деления по приоритету
                        {
                                if (z->d[i]==1)
                                        c->d[i]*=c->d[i+1];		//Умножение в стэке
                                else
                                {
                                        if (c->d[i+1]!=0)
                                        {
                                                c->d[i]/=c->d[i+1];		//Деление в стэке
                                        }
                                        else
                                        {
                                            ErrorZero=true;
                                            return 0;
                                        }
                                }
                                Smes(c,i+1);
                                Smes(z,i);
                                i--;
                        }
                        i++;
                }
                i=1;
                while(i<=z->size)
                {
                        if ((z->d[i]==3)||(z->d[i]==4))			//Нахождение сложения и вычитания по приоритету
                        {
                                if (z->d[i]==3)
                                        c->d[i]+=c->d[i+1];		//Сложение в стэке
                                else
                                        c->d[i]-=c->d[i+1];		//Вычитание в стэке
                                Smes(c,i+1);
                                Smes(z,i);
                                i--;
                        }
                        i++;
                }

        }
        return c->d[1];		//Возврат результата
}
float entry(int b)		//Функция обработки строки и формирования стэков для знаков и чисел
{
    if(ErrorZero==true)
        return 0;
        stack c,z;
        ReseT(&z);		//иницилизация стэка знаков операций
        ReseT(&c);		//иницилизация стэка чисел между знаками операций
        unsigned int i=b;
        while(i!=s.size())		//Выход как только достигается конец строки
        {
                if (s[i]=='+')			// Запись в стэк операции плюс и числа перед знаком
                {
                        z.size++;
                        z.d[z.size]=3;		//Заполнение стэка знаком "+"
                        if(Log==true)
                        {
                                c.size++;
                                buf=s.substr(p,i-p);		//Заполнение стэка чиселами
                                c.d[c.size]=atof(buf.c_str());
                        }
                        Log=true;
                        p=i+1;
                }
                if (s[i]=='-')		// Запись в стэк операции минус и числа перед знаком
                {
                        z.size++;
                        z.d[z.size]=4;			//Заполнение стэка знаком "-"
                        if(s[i-1]=='(')
                        {
                                c.size++;
                                c.d[c.size]=0;
                        }
                        else
                        {
                                if(Log==true)
                        {
                                c.size++;
                                buf=s.substr(p,i-p);			//Заполнение стэка чиселами
                                c.d[c.size]=atof(buf.c_str());
                        }
                        }
                        Log=true;
                        p=i+1;
                }
                if (s[i]=='*')							// Запись в стэк операции умножить и числа перед знаком
                {
                        z.size++;
                        z.d[z.size]=1;						//Заполнение стэка знаком "*"
                        if(Log==true)
                        {
                                c.size++;
                                buf=s.substr(p,i-p);			//Заполнение стэка чиселами
                                c.d[c.size]=atof(buf.c_str());
                        }
                        Log=true;
                        p=i+1;
                }
                if (s[i]=='/')			// Запись в стэк операции деление и числа перед знаком
                {
                        z.size++;
                        z.d[z.size]=2;		//Заполнение стэка знаком "/"
                        if(Log==true)
                        {
                                c.size++;
                                buf=s.substr(p,i-p);			//Заполнение стэка чиселами
                                c.d[c.size]=atof(buf.c_str());
                        }
                        Log=true;
                        p=i+1;
                }
                if (s[i]==')')			//Нахождение закрывающейсяоткрывающейся скобки
                {
                        buf=s.substr(p,i-p);
                        c.size++;
                        c.d[c.size]=atof(buf.c_str());
                        Log=false;
                        p=p+buf.size();	//ЗДЕСЬ БЫЛА ОШИБКА!!!!
                        return Rezult(&c,&z);	//Вызов функции подсчета и возвращение результата в скобках
                }
                if (s[i]=='(')			//Нахождение открывающейся скобки
                {
                        c.size++;
                        p=i+1;
                        c.d[c.size]=entry(i+1);	//Обработка и расчет внутри скобки (рекурсивный вызов)
                        i=p;
                }
                i++;
        }
        return Rezult(&c,&z);		//Вызов функции подсчета и возвращение результата в заданной арифметической строке
}
void f()
{
        for (int i=s.size()-1;i>0;i--)
        {
                s[i]=s[i-1];
        }
}
QString calcul(string D)
{
    ErrorZero=false;
        QString A;
        s=D;
        s+='0';
        f();
        s[0]='(';		//Заключение всей строки в скобки
        s+=')'; //для удобства вызова скобочной рекурсии
        Log=true;
        float h;
        h=entry(0);
        if(ErrorZero==true)
            return "Error";
        else
            return  A.setNum(h);
}
