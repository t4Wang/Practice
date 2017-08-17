#ifndef DEAL_H
#define DEAL_H

template<typename T>
class Deal
{
    public:
        Deal(const T &t) {};

    private:
        T t;
};

template<typename T>
class Deal
{
    public:
        templete<typename U>
        Deal(const U &u) {};
    private:
        T t;
};
#endif // DEAL_H
