#ifndef REVIEW_H
#define REVIEW_H
#include <QObject>

class Review
{
private:
QString _username;
QString _review;
public:
Review(QString username,QString review):_username(username),_review(review){};
Review(QString review)
{
    this->_username=review.section(':',0,0);
    this->_review=review.section(':',1,1);
}
QString get_username(){return _username;};
QString get_review() {return _review;};
};

#endif // REVIEW_H
