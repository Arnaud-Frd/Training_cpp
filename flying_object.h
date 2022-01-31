#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

class flying_object
{
private:
    int flag=0;
protected:
    int state;
    int identifiant;

public:
    flying_object();
    virtual ~flying_object();
    flying_object(int id);
    int CheckWeather();
    virtual int fly();
    virtual void log();
};

#endif // FLYING_OBJECT_H
