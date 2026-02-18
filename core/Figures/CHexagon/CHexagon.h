#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "Figures/CFigure/CFigure.h"
#include "CProperties/CProperties.h"
#include <sstream>

class CHexagon : public CFigure {

    int centerX;
    int centerY;
    int size;

    QColor fillColor;
    QColor outColor;

    public:

    CHexagon();
    virtual void draw(QPainter& painter) override;
    void setProperties(CProperties& prop);
    
    virtual std::string serialize() const override;
    virtual std::string getType() const override;
    static CHexagon* deserialize(const std::string& data);

};

#endif//CHEXAGON_H