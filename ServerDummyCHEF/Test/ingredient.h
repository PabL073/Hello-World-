#ifndef INGREDIENT_H
#define INGREDIENT_H
#include<QObject>


class Ingredient
{
private:
    QString _denumire;
    QString _gramaj;

public:
    Ingredient(QString ingredient)
    {
        this->_denumire=ingredient.section('-',1,1);
        this->_gramaj=ingredient.section('-',0,0);
    }
    Ingredient(QString denumire,QString gramaj):_denumire(denumire),_gramaj(gramaj) {};
    QString get_denumire() {return _denumire;};
    QString get_gramaj() {return _gramaj;};
};

#endif // INGREDIENT_H
