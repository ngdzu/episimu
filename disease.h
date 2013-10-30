#ifndef DISEASE_H
#define DISEASE_H

class Disease
{

private:
    float percentInfected;
    float percentDead;
    bool hasImmunity;
    int contagiousTime;
    int incubatingTime;

public:
    Disease();

    Disease(float percentInfected,
            float percentDead,
            bool hasImmunity,
            int contagiousTime,
            int incubatingTime);

};

#endif // DISEASE_H
