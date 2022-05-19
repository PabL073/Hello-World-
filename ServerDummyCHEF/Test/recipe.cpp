#include "recipe.h"

QString Recipe::get_ingredients()
{
    QString ingredients;
    for(auto it=this->_ingredients.begin(); it!=this->_ingredients.end();it++)
    {
        ingredients.append(it->get_gramaj());
        ingredients.append("-");
        ingredients.append(it->get_denumire());
        ingredients.append(",");
    };
    return ingredients;
};

void Recipe::set_ingredients(QString ingredients)
{
    int i=0;
    QString ingredient=ingredients.section(',',i,i);
    do
    {
        Ingredient ing(ingredient);
        i++;
        _ingredients.push_back(ing);
        ingredient=ingredients.section(',',i,i);
    }while(ingredient.length()!=0);
};

void Recipe::set_ingredients_add(QString ingredients)
{
    int i=0;
    QString ingredient=ingredients.section('/',i,i);
    i++;
    QString gramaj=ingredients.section('/',i,i);
    do
    {
        Ingredient ing(ingredient,gramaj);
        i++;
        _ingredients.push_back(ing);
        ingredient=ingredients.section('/',i,i);
        i++;
        gramaj=ingredients.section('/',i,i);
    }while(ingredients.length()!=0);
}

void Recipe::set_reviews(QString reviews)
{
    int i=0;
    QString review=reviews.section(',',i,i);
    do
    {
        Review rev(review);
        i++;
        _reviews.push_back(rev);
        review=reviews.section(',',i,i);
    }while(review.length()!=0);
}
