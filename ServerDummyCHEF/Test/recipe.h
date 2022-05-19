#ifndef RECIPE_H
#define RECIPE_H
#include "ingredient.h"
#include "review.h"

class Recipe
{
public:
    std::list <Ingredient> _ingredients;
    std::list <Review> _reviews;

private:
    QString _name;
    QString _chefname;
    QString _steps;
    QString _image;
    float _nota;

public:
    Recipe() {};
    Recipe(QString name, QString chefname):_name(name),_chefname(chefname) {};

    QString get_name(){return this->_name;};
    QString get_chefname() {return this->_chefname;};
    QString get_steps() {return this->_steps;};
    QString get_image() {return this->_image;};
    float get_nota() {return this->_nota;};
    QString get_ingredients();

    void set_ingredients(QString ingredients);
    void set_ingredients_add(QString ingredients);

    void set_steps(QString steps){this->_steps=steps;};
    void set_image(QString image) {this->_image=image;};
    void set_reviews(QString reviews);
    void set_nota(float nota) {this->_nota=nota;};

     void add_ingredients(QString str1,QString str2)
    {
        this->_ingredients.push_back(Ingredient(str2,str1));
    }
};

#endif // RECIPE_H
