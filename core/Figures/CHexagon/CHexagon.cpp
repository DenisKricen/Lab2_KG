#include "CHexagon.h"

CHexagon::CHexagon() {

    size=0;
    centerX=0;
    centerY=0;

    fillColor= Qt::black;
    outColor= Qt::black;
}

void CHexagon::setProperties(CProperties& prop) {
    size=prop.circumradius;
    centerX=prop.abscise;    
    centerY=prop.ordinate;   
    fillColor=prop.fillColor;
    outColor=prop.outColor;
}

void CHexagon::draw(QPainter& painter) {
    QPen pen(outColor, 2);
    pen.setCosmetic(true);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setMiterLimit(10.0);
    
    painter.setPen(pen);
    painter.setBrush(fillColor);
    painter.save();
    
    painter.translate(centerX, -centerY);

    QPolygonF hexagon;
    for (int i = 0; i < 6; i++) {
        double angle = M_PI / 3.0 * i;
        double dx = size * cos(angle);
        double dy = size * sin(angle);
        
        hexagon << QPointF(dx, -dy);
    }
    painter.drawPolygon(hexagon);

    painter.restore();
}